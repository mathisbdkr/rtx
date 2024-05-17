/*
** EPITECH PROJECT, 2024
** Ray.cpp
** File description:
** ray class
*/

#include "Ray.hpp"
#include "Vector3D.hpp"

rtx::Ray::Ray()
    : origin()
    , direction()
    , time(0)
    {}

rtx::Ray::Ray(rtx::Point3D origin, rtx::Vector3D direction)
    : origin(origin)
    , direction(direction)
    , time(0)
    {}

rtx::Ray::Ray(rtx::Point3D origin, rtx::Vector3D direction, double time)
    : origin(origin)
    , direction(direction)
    , time(time)
    {}

rtx::Ray::Ray(const Ray &other)
    : origin(other.origin)
    , direction(other.direction)
    {}

rtx::Point3D rtx::Ray::at(double t) const
{
    return origin + (direction * t);
}
