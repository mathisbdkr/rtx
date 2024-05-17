/*
** EPITECH PROJECT, 2024
** merge
** File description:
** Torus
*/

#include "Torus.hpp"
#include "Vector3D.hpp"
#include "Interval.hpp"
#include <cmath>
#include <iostream>

rtx::Torus::Torus() : _majorRadius(1.0), _minorRadius(0.5)
{
    _material = nullptr;
    _center = rtx::Point3D();
}

rtx::Torus::Torus(rtx::Point3D center, double majorRadius, double minorRadius, std::shared_ptr<rtx::IMaterial> material)
    : _majorRadius(majorRadius), _minorRadius(minorRadius), _center(center)
{
    _material = material;
}


bool rtx::Torus::hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const
{
    rtx::Point3D origin = ray.origin - _center;
    rtx::Vector3D direction = ray.direction;

    double a = direction.x * direction.x + direction.y * direction.y + direction.z * direction.z;
    double b = 2.0 * (direction.x * origin.x + direction.y * origin.y + direction.z * origin.z);
    double c = origin.x * origin.x + origin.y * origin.y + origin.z * origin.z +
               _majorRadius * _majorRadius - _minorRadius * _minorRadius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0.0)
        return false;

    double root = (-b - sqrt(discriminant)) / (2.0 * a);
    if (!rayT.surrounds(root)) {
        root = (-b + sqrt(discriminant)) / (2.0 * a);
        if (!rayT.surrounds(root))
            return false;
    }

    rec.t = root;
    rec.point = ray.at(rec.t);

    double temp = rec.point.x * rec.point.x + rec.point.y * rec.point.y + rec.point.z * rec.point.z + _majorRadius * _majorRadius -
                  _minorRadius * _minorRadius;
    rec.v = 2.0 * rec.point.z * (rec.point.x * rec.point.x + rec.point.y * rec.point.y - _majorRadius * _majorRadius -
                                 _minorRadius * _minorRadius) / temp;

    rec.u = 2.0 * sqrt(rec.point.x * rec.point.x + rec.point.y * rec.point.y) * (_majorRadius * _majorRadius + _minorRadius * _minorRadius -
                                                                                 rec.point.z * rec.point.z - rec.v * _minorRadius * rec.v * _minorRadius) /
            temp;

    rec.material = _material;
    rec.setFaceNormal(ray, rec.point - rtx::Point3D(0, 0, 0));
    return true;
}
