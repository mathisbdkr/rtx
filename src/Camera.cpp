/*
** EPITECH PROJECT, 2024
** Camera.cpp
** File description:
** camera class
*/

#include "Camera.hpp"
#include "IPC.hpp"
#include <iostream>
#include <iomanip>
#include <thread>
#include "Light.hpp"

rtx::Camera::Camera(int imageWidth, int imageHeight)
    : imageSize(std::make_pair(imageWidth, imageHeight))
    , _intensity(rtx::Interval(0.0, 0.9))
{
    initialize();
}

rtx::Camera::Camera() : _intensity(rtx::Interval(0.0, 0.9))
{
    initialize();
}

rtx::Color rtx::Camera::getRayColor(const rtx::Ray &ray, int depth, const rtx::IShape &shape) const
{
    rtx::HitRecord rec;

    if (depth <= 0)
        return rtx::Color();
    if (!shape.hits(ray, rtx::Interval(0.001, infinity), rec))
        return backgroundColor;

    rtx::Ray reflected;
    rtx::Color attenuation;
    rtx::Light light;
    rtx::Color colorFromEmission = rec.material->lightEmission(rec.u, rec.v, rec.point);

    if (rec.material->reflect(ray, rec, attenuation, reflected)) {
        rtx::Color finalColor = attenuation * getRayColor(reflected, depth - 1, shape);
        light.ambientLight(ambientLight, finalColor, attenuation);
        return finalColor;
    }
    return colorFromEmission;
}

rtx::Ray rtx::Camera::getRay(double u, double v) const
{
    auto offset = getSampleSquare();
    rtx::Point3D pixelSample = _pixelOrigin + (_pixelU * (offset.x + u)) + (_pixelV * (offset.y + v));
    rtx::Point3D rayOrigin = (defocusAngle <= 0.0) ? _origin : defocusDiskSample();
    rtx::Vector3D rayDirection = pixelSample - _origin;

    return rtx::Ray(rayOrigin, rayDirection);
}

rtx::Point3D rtx::Camera::defocusDiskSample() const
{
    rtx::Vector3D vect = rtx::Vector3D::randomInUnitDisk();

    return _origin + (_defocusX * vect.x) + (_defocusY * vect.y);
}

void rtx::Camera::processPixels(std::stringstream &str, std::size_t yMin, std::size_t yMax, const rtx::IShape &shape)
{
    for (std::size_t y = yMin; y < yMax; ++y) {
        for (std::size_t x = 0; x < imageSize.first; ++x) {
            rtx::Color pixelColor;
            for (std::size_t sample = 0; sample < samplesPerPixel; ++sample) {
                rtx::Ray ray = getRay(x, y);
                pixelColor += getRayColor(ray, maxDepth, shape);
            }
            pixelColor *= _pixelSampleScale;
            pixelColor.correctGamma();
            pixelColor.smoothenPixels(_intensity);
            str << pixelColor << '\n';
        }
    }
}

void rtx::Camera::render(const rtx::IShape &shape, const std::string &sceneFileName)
{
    initialize();

    std::size_t firstExtensionChar = sceneFileName.find(".cfg");
    std::string configFileName = sceneFileName;
    std::ofstream ppmFile;
    rtx::IPC process(std::thread::hardware_concurrency() * 3);

    if (firstExtensionChar == std::string::npos)
        throw rtx::Camera::InvalidFileExtension();
    configFileName.erase(firstExtensionChar, configFileName.length());
    process.launch<rtx::Camera>(&rtx::Camera::processPixels, *this, shape, imageSize.second);
    ppmFile.open(configFileName + ".ppm", std::ios::trunc);
    ppmFile << "P3\n" << imageSize.first << ' ' << imageSize.second << "\n255\n";
    ppmFile << process.recoverValues(BUFSIZ).str();
    ppmFile.close();
}

void rtx::Camera::renderGraphical(const rtx::IShape &shape, const std::string& sceneFileName)
{
    render(shape, sceneFileName);
}

void rtx::Camera::initialize()
{
    _pixelSampleScale = 1.0 / double(samplesPerPixel);
    _origin = cameraPosition;

    double vh = 2.0 * (std::tan(degToRad(fov) / 2.0)) * focusDist;

    rtx::Vector3D w = (cameraPosition - lookAt).unitVector();
    rtx::Vector3D u = (cameraAngle).cross(w).unitVector();
    rtx::Vector3D v = w.cross(u);

    rtx::Vector3D viewU = u * (vh * (double(imageSize.first) / imageSize.second));
    _pixelU = viewU / double(imageSize.first);
    rtx::Vector3D viewV = -v * vh;
    _pixelV = viewV / double(imageSize.second);
    rtx::Point3D viewportOrigin = _origin - (w * (focusDist)) - (viewU / 2.0) - (viewV / 2.0);
    _pixelOrigin = viewportOrigin + ((_pixelU + _pixelV) * 0.5);
    double defocusRad = focusDist * std::tan(degToRad(defocusAngle / 2.0));
    _defocusX = u * defocusRad;
    _defocusY = v * defocusRad;
}
