/*
** EPITECH PROJECT, 2024
** Camera.hpp
** File description:
** camera class
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Ray.hpp"
    #include "Vector3D.hpp"
    #include "Color.hpp"
    #include "IShape.hpp"
    #include "macros.hpp"
    #include "Error.hpp"
    #include <vector>
    #include <mutex>
    #include <fstream>

namespace rtx
{
    class Camera
    {
        private:
            const rtx::Interval _intensity;
            rtx::Point3D _pixelOrigin;
            rtx::Vector3D _pixelU;
            rtx::Vector3D _pixelV;
            rtx::Point3D _origin;
            double _pixelSampleScale;
            rtx::Vector3D _defocusX;
            rtx::Vector3D _defocusY;

            void initialize();
            rtx::Color getRayColor(const rtx::Ray &ray, int depth, const rtx::IShape &shape) const;
            rtx::Vector3D getSampleSquare() const {return rtx::Vector3D(randomValue() - 0.5, randomValue() - 0.5, 0.0);}
            rtx::Point3D defocusDiskSample() const;

        public:
            class InvalidFileExtension : public virtual rtx::Error
            {
                public:
                    InvalidFileExtension() noexcept {
                        _message = "invalid file extension";
                    }

                    const char *what() const noexcept override {return _message.c_str();}
            };
            Camera();
            Camera(int imageWidth, int imageHeight);
            ~Camera() = default;

            std::size_t samplesPerPixel = 250;
            std::size_t maxDepth = 50;
            std::pair<std::size_t, std::size_t> imageSize = std::make_pair(256, 256);
            double fov = 90.0;
            rtx::Point3D cameraPosition = rtx::Point3D();
            rtx::Point3D lookAt = rtx::Point3D(0.0, 0.0, -1.0);
            rtx::Vector3D cameraAngle = rtx::Vector3D(0.0, 1.0, 0.0);
            double defocusAngle = 0.0;
            double focusDist = 10.0;
            rtx::Color backgroundColor = rtx::Color();
            double ambientLight = 0.0;

            void processPixels(std::stringstream &str, std::size_t yMin, std::size_t yMax, const rtx::IShape &shape);
            rtx::Ray getRay(double u, double v) const;
            void render(const rtx::IShape &shape, const std::string& sceneFileName);
            void renderGraphical(const rtx::IShape &shape, const std::string& sceneFileName);
    };
}

#endif
