/*
** EPITECH PROJECT, 2024
** Rotation.cpp
** File description:
** rotation of rays
*/

#include "Rotation.hpp"
#include "Matrix3D.hpp"
#include "macros.hpp"
#include <iostream>

rtx::Rotation::Rotation(std::shared_ptr<rtx::IShape> shape, const rtx::Vector3D &axis, double angle)
    : _theta(degToRad(angle))
{
    _axis = axis;
    _shape = shape;
    _bBox = shape->getBoundingBox();

    rtx::Point3D min(infinity, infinity, infinity);
    rtx::Point3D max(-infinity, -infinity, -infinity);

    for (std::size_t i = 0; i < 3; ++i) {
        if (axis[i] != 0.0)
            _rotationMatrix = getRotationMatrix(i);
    }
    for (std::size_t i = 0; i < 3; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            for (std::size_t k = 0; k < 3; ++k) {
                rtx::Vector3D tmp(
                    i * _bBox.x.max + (1 - i) * _bBox.x.min,
                    j * _bBox.y.max + (1 - j) * _bBox.y.min,
                    k * _bBox.z.max + (1 - k) * _bBox.z.min
                );
                tmp = _rotationMatrix * tmp;
                for (std::size_t l = 0; l < 3; ++l) {
                    min[l] = std::fmin(min[l], tmp[l]);
                    max[l] = std::fmax(max[l], tmp[l]);
                }
            }
        }
    }
    _bBox = rtx::BoundingBox(min, max);
}

rtx::Matrix3D rtx::Rotation::getRotationMatrix(std::size_t axis) const
{
    switch (axis) {
    case 0:
        return rtx::Matrix3D(
            rtx::Vector3D(1.0, 0.0, 0.0),
            rtx::Vector3D(0.0, cos(_theta), sin(_theta)),
            rtx::Vector3D(0.0, -sin(_theta), cos(_theta))
        );
    case 1:
        return rtx::Matrix3D(
            rtx::Vector3D(cos(_theta), 0.0, -sin(_theta)),
            rtx::Vector3D(0.0, 1.0, 0.0),
            rtx::Vector3D(sin(_theta), 0.0, cos(_theta))
        );
    case 2:
        return rtx::Matrix3D(
            rtx::Vector3D(cos(_theta), sin(_theta), 0.0),
            rtx::Vector3D(-sin(_theta), cos(_theta), 0.0),
            rtx::Vector3D(0.0, 0.0, 1.0)
        );
    default:
        throw std::out_of_range("Invalid index " + std::to_string(axis));
    }
}

rtx::Matrix3D rtx::Rotation::getInvertedRotationMatrix(std::size_t axis) const
{
    switch (axis) {
    case 0:
        return rtx::Matrix3D(
            rtx::Vector3D(1.0, 0.0, 0.0),
            rtx::Vector3D(0.0, cos(_theta), -sin(_theta)),
            rtx::Vector3D(0.0, sin(_theta), cos(_theta))
        );
    case 1:
        return rtx::Matrix3D(
            rtx::Vector3D(cos(_theta), 0.0, sin(_theta)),
            rtx::Vector3D(0.0, 1.0, 0.0),
            rtx::Vector3D(-sin(_theta), 0.0, cos(_theta))
        );
    case 2:
        return rtx::Matrix3D(
            rtx::Vector3D(cos(_theta), -sin(_theta), 0.0),
            rtx::Vector3D(sin(_theta), cos(_theta), 0.0),
            rtx::Vector3D(0.0, 0.0, 1.0)
        );
    default:
        throw std::out_of_range("Invalid index " + std::to_string(axis));
    }
}

bool rtx::Rotation::hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const
{
    rtx::Ray rotatedRay(_rotationMatrix * ray.origin, _rotationMatrix * ray.direction, ray.time);

    if (_shape->hits(rotatedRay, rayT, rec) == false)
        return false;
    rtx::Matrix3D invRotationMatrix;
    for (std::size_t i = 0; i < 3; ++i) {
        if (_axis[i] != 0.0)
            invRotationMatrix = getInvertedRotationMatrix(i);
    }
    rec.point = invRotationMatrix * rec.point;
    rec.normal = invRotationMatrix * rec.normal;
    return true;
}
