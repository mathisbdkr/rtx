/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-yanis.harkouk
** File description:
** Triangle
*/

#include "Triangle.hpp"

rtx::Triangle::Triangle() :
    _p0(),
    _p1(),
    _p2()
{
    updateCenter();
    _material = nullptr;
}

rtx::Triangle::Triangle(rtx::Point3D p0, rtx::Point3D p1, rtx::Point3D p2, std::shared_ptr<rtx::IMaterial> material) :
    _p0(p0),
    _p1(p1),
    _p2(p2)
{
    updateCenter();
    _material = material;
}

void rtx::Triangle::updateCenter()
{
    center = rtx::Point3D((_p0.x + _p1.x + _p2.x) / 3.0, (_p0.y + _p1.y + _p2.y) / 3.0, (_p0.z + _p1.z + _p2.z) / 3.0);
}

bool rtx::Triangle::hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const
{
    rtx::Ray tmpRay = ray;
    rtx::Vector3D firstEdge = _p1 - _p0;
    rtx::Vector3D secondEdge = _p2 - _p0;
    rtx::Vector3D tmpVect1 = tmpRay.direction.cross(secondEdge);
    double d = firstEdge.dot(tmpVect1);
    double u = 0.0;
    double v = 0.0;

    if (!rayT.surrounds(d))
        return false;
    rtx::Vector3D tmpVect2 = tmpRay.origin - _p0;
    rtx::Vector3D tmpVect3 = tmpVect2.cross(firstEdge);
    u = (1.0/d) * (tmpVect2.dot(tmpVect1));
    v = (1.0/d) * ray.direction.dot(tmpVect3);
    if (u < 0.0 || u > 1.0)
        return false;
    if (v < 0.0 || u + v > 1.0)
        return false;
    double distance = (1.0/d) * secondEdge.dot(tmpVect3);
    if (rayT.surrounds(distance)) {
        rec.material = _material;
        return true;
    }
    return false;
}
