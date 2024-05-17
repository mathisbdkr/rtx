/*
** EPITECH PROJECT, 2024
** Translation.cpp
** File description:
** translation of rays
*/

#include "Translation.hpp"
#include "Matrix3D.hpp"

rtx::Translation::Translation(std::shared_ptr<rtx::IShape> shape, const rtx::Vector3D &axis)
{
    _axis = axis;
    _shape = shape;
    _bBox = shape->getBoundingBox() + axis;
}

bool rtx::Translation::hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const
{
    rtx::Ray offsetRay(ray.origin - _axis, ray.direction, ray.time);

    if (_shape->hits(offsetRay, rayT, rec) == false)
        return false;
    rec.point += _axis;
    return true;
}
