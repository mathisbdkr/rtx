/*
** EPITECH PROJECT, 2024
** backup
** File description:
** Plane
*/

#include "Plane.hpp"
#include "BoundingBox.hpp"

rtx::Plane::Plane() : _position(), _xVector(), _yVector()
{
    _bBox = rtx::BoundingBox();
    _material = nullptr;
}

rtx::Plane::Plane(const rtx::Point3D &position, const rtx::Vector3D &xVector, const rtx::Vector3D &yVector, std::shared_ptr<rtx::IMaterial> mat) : _position(position), _xVector(xVector), _yVector(yVector)
{
    update();
    _material = mat;
}

void rtx::Plane::update()
{
    auto n = _xVector.cross(_yVector);
    normal = n.unitVector();
    D = normal.dot(_position);
    _w = n / n.dot(n);
    _bBox = rtx::BoundingBox(rtx::BoundingBox(_position, _position + _xVector + _yVector), rtx::BoundingBox(_position + _xVector, _position + _yVector));
}

bool rtx::Plane::hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const
{
    double denom = normal.dot(ray.direction);

    if (fabs(denom) < 0.00000001)
        return false;

    double t = (D - normal.dot(ray.origin)) / denom;
    if (!rayT.contains(t))
        return false;

    rtx::Point3D hitPoint = ray.at(t);
    rtx::Vector3D planIntersectionVect = hitPoint - _position;
    rtx::Vector3D newU = _xVector;
    double alpha = _w.dot(planIntersectionVect.cross(_yVector));
    double beta =  _w.dot(newU.cross(planIntersectionVect));

    rtx::Interval unitInterval = rtx::Interval(0, 1);
    if (!unitInterval.contains(alpha) || !unitInterval.contains(beta))
        return false;

    rec.u = alpha;
    rec.v = beta;
    rec.t = t;
    rec.point = hitPoint;
    rec.material = _material;
    rec.setFaceNormal(ray, normal);

    return true;
}
