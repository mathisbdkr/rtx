/*
** EPITECH PROJECT, 2024
** Box.cpp
** File description:
** box shape
*/

#include "Box.hpp"
#include "Scene.hpp"
#include "Vector3D.hpp"
#include "Factory.hpp"

rtx::Box::Box(const rtx::Point3D &a, const rtx::Point3D &b, std::shared_ptr<rtx::IMaterial> material)
{
    rtx::Point3D min(std::fmin(a.x, b.x), std::fmin(a.y, b.y), std::fmin(a.z, b.z));
    rtx::Point3D max(std::fmax(a.x, b.x), std::fmax(a.y, b.y), std::fmax(a.z, b.z));
    rtx::Vector3D dx(max.x - min.x, 0.0, 0.0);
    rtx::Vector3D dy(0.0, max.y - min.y, 0.0);
    rtx::Vector3D dz(0.0, 0.0, max.z - min.z);

    _sides.add(std::make_shared<rtx::Plane>(rtx::Point3D(min.x, min.y, max.z), dx, dy, material));   // front
    _sides.add(std::make_shared<rtx::Plane>(rtx::Point3D(max.x, min.y, min.z), -dx, dy, material));  // back
    _sides.add(std::make_shared<rtx::Plane>(rtx::Point3D(max.x, min.y, max.z), -dz, dy, material));  // right
    _sides.add(std::make_shared<rtx::Plane>(rtx::Point3D(min.x, min.y, min.z), dz, dy, material));   // left
    _sides.add(std::make_shared<rtx::Plane>(rtx::Point3D(min.x, max.y, max.z), dx, -dz, material));  // top
    _sides.add(std::make_shared<rtx::Plane>(rtx::Point3D(min.x, min.y, min.z), dx, dz, material));   // bottom
}

bool rtx::Box::hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const
{
    return _sides.hits(ray, rayT, rec);
}
