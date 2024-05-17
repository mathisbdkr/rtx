/*
** EPITECH PROJECT, 2024
** rtx
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Parsing.hpp"
#include "Vector3D.hpp"
#include "macros.hpp"
#include "SphereBuilder.hpp"
#include "ConeBuilder.hpp"
#include "CylinderBuilder.hpp"
#include "PlaneBuilder.hpp"
#include "TriangleBuilder.hpp"
#include <vector>
#include <libconfig.h++>
#include "Rotation.hpp"
#include "Translation.hpp"
#include "Torus.hpp"
#include <memory>

rtx::Factory::Factory(libconfig::Config &conf) : _conf(conf)
{
}

void rtx::Factory::createWorldFromConfFile(rtx::Scene &world) const noexcept
{
    createPlaneFromConfFile(world);
    createConeFromConfFile(world);
    createCylinderFromConfFile(world);
    createSphereFromConfFile(world);
    createTriangleFromConfFile(world);
    createLightFromConfFile(world);
    createDirectionalLightFromConfFile(world);
}

std::shared_ptr<rtx::IShape> rtx::Factory::applyTransformations(std::vector<rtx::Parsing::TransfoInfo> &transfoInfos, std::shared_ptr<rtx::IShape> shape) const
{
    for (auto &transfoInfo : transfoInfos) {
        if (transfoInfo.transformation == "translation")
            shape = rtx::Factory::createTransformation<rtx::Translation>(shape, rtx::Vector3D(transfoInfo.x, transfoInfo.y, transfoInfo.z));
        if (transfoInfo.transformation == "rotation")
            shape = rtx::Factory::createTransformation<rtx::Rotation>(shape, rtx::Vector3D(transfoInfo.x, transfoInfo.y, transfoInfo.z), transfoInfo.angle);
    }
    return shape;
}

void rtx::Factory::createSphereFromConfFile(rtx::Scene &world) const noexcept
{
    rtx::SphereBuilder builder;
    std::vector<rtx::Parsing::SphereInfo> spheres = rtx::Parsing::parseSphere(_conf);

    for (auto &sphere : spheres) {
        builder.setPosition(rtx::Point3D(sphere.x, sphere.y, sphere.z));
        builder.setRadius(sphere.radius);
        if (sphere.material.material == "Dielectric")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Dielectric>(sphere.material.extra));
        if (sphere.material.material == "Matte")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Matte>(rtx::Color(sphere.material.r, sphere.material.g, sphere.material.b)));
        if (sphere.material.material == "Light")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Light>(rtx::Color(sphere.material.r, sphere.material.g, sphere.material.b)));
        if (sphere.material.material == "Metal")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Metal>(rtx::Color(sphere.material.r, sphere.material.g, sphere.material.b), sphere.material.extra));
        world.add(applyTransformations(sphere.material.transfo, builder.getProduct()));
    }

    auto material1 = std::make_shared<rtx::Dielectric>(1.5);

    int numSpheres = 300;

    double circleRadius = 2.0;

    for (int i = 0; i < numSpheres; ++i) {
        double angle = 2.0 * M_PI * i / numSpheres;

        double x = circleRadius * std::cos(angle);
        double y = circleRadius * std::sin(angle);

        world.add(std::make_shared<rtx::Sphere>(rtx::Point3D(x, 0, y), 0.8, material1));
    }

    circleRadius = 4;

    for (int i = 0; i < numSpheres; ++i) {
        double angle = 2.0 * M_PI * i / numSpheres;

        double x = circleRadius * std::cos(angle);
        double y = circleRadius * std::sin(angle);

        world.add(std::make_shared<rtx::Sphere>(rtx::Point3D(x, 0, y), 0.5, material1));
    }

    circleRadius = 5.5;

    for (int i = 0; i < numSpheres; ++i) {
        double angle = 2.0 * M_PI * i / numSpheres;

        double x = circleRadius * std::cos(angle);
        double y = circleRadius * std::sin(angle);

        world.add(std::make_shared<rtx::Sphere>(rtx::Point3D(x, 0, y), 0.3, material1));
    }
}

void rtx::Factory::createCylinderFromConfFile(rtx::Scene &world) const noexcept
{
    rtx::CylinderBuilder builder;
    std::vector<rtx::Parsing::CylinderConeInfo> cylinders = rtx::Parsing::parseCylinder(_conf);

        for (auto &cylinder : cylinders) {
            builder.setPosition(rtx::Point3D(cylinder.x, cylinder.y, cylinder.z));
            builder.setRadius(cylinder.radius);
            builder.setHeight(cylinder.height);
            builder.setIsCapped(cylinder.isCapped);
            if (cylinder.material.material == "Dielectric")
                builder.setMaterial(rtx::Factory::createMaterial<rtx::Dielectric>(cylinder.material.extra));
            if (cylinder.material.material == "Matte")
                builder.setMaterial(rtx::Factory::createMaterial<rtx::Matte>(rtx::Color(cylinder.material.r, cylinder.material.g, cylinder.material.b)));
            if (cylinder.material.material == "Light")
                builder.setMaterial(rtx::Factory::createMaterial<rtx::Light>(rtx::Color(cylinder.material.r, cylinder.material.g, cylinder.material.b)));
            if (cylinder.material.material == "Metal")
                builder.setMaterial(rtx::Factory::createMaterial<rtx::Metal>(rtx::Color(cylinder.material.r, cylinder.material.g, cylinder.material.b), cylinder.material.extra));
            world.add(applyTransformations(cylinder.material.transfo, builder.getProduct()));
    }
}

void rtx::Factory::createConeFromConfFile(rtx::Scene &world) const noexcept
{
    rtx::ConeBuilder builder;
    std::vector<rtx::Parsing::CylinderConeInfo> cones = rtx::Parsing::parseCone(_conf);

        for (auto &cone : cones) {
            builder.setPosition(rtx::Point3D(cone.x, cone.y, cone.z));
            builder.setRadius(cone.radius);
            builder.setHeight(cone.height);
            if (cone.material.material == "Dielectric")
                builder.setMaterial(rtx::Factory::createMaterial<rtx::Dielectric>(cone.material.extra));
            if (cone.material.material == "Matte")
                builder.setMaterial(rtx::Factory::createMaterial<rtx::Matte>(rtx::Color(cone.material.r, cone.material.g, cone.material.b)));
            if (cone.material.material == "Light")
                builder.setMaterial(rtx::Factory::createMaterial<rtx::Light>(rtx::Color(cone.material.r, cone.material.g, cone.material.b)));
            if (cone.material.material == "Metal")
                builder.setMaterial(rtx::Factory::createMaterial<rtx::Metal>(rtx::Color(cone.material.r, cone.material.g, cone.material.b), cone.material.extra));
            world.add(applyTransformations(cone.material.transfo, builder.getProduct()));
    }
}

void rtx::Factory::createPlaneFromConfFile(rtx::Scene &world) const noexcept
{
    rtx::PlaneBuilder builder;
    std::vector<rtx::Parsing::PlaneTriangleInfo> planes = rtx::Parsing::parsePlane(_conf);

    for (auto &plane : planes) {
        builder.setPosition(rtx::Point3D(plane.x, plane.y, plane.z));
        builder.setWidth(rtx::Vector3D(plane.size_x, plane.size_y, plane.size_z));
        builder.setHeight(rtx::Vector3D(plane.height_x, plane.height_y, plane.height_z));
        if (plane.material.material == "Dielectric")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Dielectric>(plane.material.extra));
        if (plane.material.material == "Matte")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Matte>(rtx::Color(plane.material.r, plane.material.g, plane.material.b)));
        if (plane.material.material == "Light")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Light>(rtx::Color(plane.material.r, plane.material.g, plane.material.b)));
        if (plane.material.material == "Metal")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Metal>(rtx::Color(plane.material.r, plane.material.g, plane.material.b), plane.material.extra));
        world.add(applyTransformations(plane.material.transfo, builder.getProduct()));
    }
}

void rtx::Factory::createTriangleFromConfFile(rtx::Scene &world) const noexcept
{
    rtx::TriangleBuilder builder;
    std::vector<rtx::Parsing::PlaneTriangleInfo> triangles = rtx::Parsing::parseTriangles(_conf);

    for (auto &triangle : triangles) {
        builder.setPoint0(rtx::Point3D(triangle.x, triangle.y, triangle.z));
        builder.setPoint1(rtx::Point3D(triangle.size_x, triangle.size_y, triangle.size_z));
        builder.setPoint2(rtx::Point3D(triangle.height_x, triangle.height_y, triangle.height_z));
        builder.setPosition(rtx::Point3D());
        if (triangle.material.material == "Dielectric")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Dielectric>(triangle.material.extra));
        if (triangle.material.material == "Matte")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Matte>(rtx::Color(triangle.material.r, triangle.material.g, triangle.material.b)));
        if (triangle.material.material == "Light")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Light>(rtx::Color(triangle.material.r, triangle.material.g, triangle.material.b)));
        if (triangle.material.material == "Metal")
            builder.setMaterial(rtx::Factory::createMaterial<rtx::Metal>(rtx::Color(triangle.material.r, triangle.material.g, triangle.material.b), triangle.material.extra));
        world.add(applyTransformations(triangle.material.transfo, builder.getProduct()));
    }
}

void rtx::Factory::createLightFromConfFile(rtx::Scene &world) const noexcept
{
    std::vector<rtx::Parsing::LightInfo> lightPoints = rtx::Parsing::parsePointLight(_conf);

    for (auto &lightPoint : lightPoints) {
        auto light = std::make_shared<rtx::Light>(rtx::Color(lightPoint.r, lightPoint.g, lightPoint.b));
        world.add(createShape<rtx::Sphere>(rtx::Point3D(lightPoint.x, lightPoint.y, lightPoint.z), lightPoint.size, light));
    }
}

void rtx::Factory::createDirectionalLightFromConfFile(rtx::Scene &world) const noexcept
{
    std::vector<rtx::Parsing::DirectionalLightInfo> lightPoints = rtx::Parsing::parseDirectionalLight(_conf);

    for (auto &lightPoint : lightPoints) {
        auto light = std::make_shared<rtx::Light>(rtx::Color(lightPoint.r, lightPoint.g, lightPoint.b));
        world.add(createShape<rtx::Sphere>(rtx::Point3D(lightPoint.x, lightPoint.y, lightPoint.z), lightPoint.size, light));
        auto black = std::make_shared<rtx::Matte>(rtx::Color(0.0, 0.0, 0.0));
        rtx::Point3D pos = rtx::Point3D(lightPoint.x, lightPoint.y, lightPoint.z);

        rtx::Point3D lookat = rtx::Point3D(lightPoint.x2, lightPoint.y2, lightPoint.z2);

        world.add(createShape<rtx::Sphere>(pos, lightPoint.size, light));

        rtx::Vector3D tmp = rtx::Vector3D(lookat.x - lightPoint.x, lookat.y - lightPoint.y, lookat.z - lightPoint.z).unitVector();

        double yaw = -std::atan2(tmp.y + (lightPoint.size / 2.0), tmp.x + (lightPoint.size / 2.0)) * (180.0 / M_PI);
        double pitch = -std::asin(tmp.z) * (180.0 / M_PI);

        auto cylinder = createShape<rtx::Cylinder>(rtx::Point3D(0.0, 0.0, 0.0), lightPoint.size, lightPoint.size * 10, black);

        cylinder = std::make_shared<rtx::Rotation>(cylinder, rtx::Vector3D(0, 0, 1), yaw);
        cylinder = std::make_shared<rtx::Rotation>(cylinder, rtx::Vector3D(1, 0, 0), pitch);
        cylinder = std::make_shared<rtx::Translation>(cylinder, pos);
        world.add(cylinder);
    }
}
