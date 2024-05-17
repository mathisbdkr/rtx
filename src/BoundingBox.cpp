/*
** EPITECH PROJECT, 2024
** BoundingBox.cpp
** File description:
** axis aligned bounding box
*/

#include "BoundingBox.hpp"

rtx::BoundingBox::BoundingBox()
{
}

rtx::BoundingBox::BoundingBox(const rtx::Interval &x, const rtx::Interval &y, const rtx::Interval &z)
    : x(x)
    , y(y)
    , z(z)
{
    padToMin();
}

rtx::BoundingBox::BoundingBox(const rtx::Point3D &a, const rtx::Point3D &b)
{
    x = rtx::Interval(std::fmin(a.x, b.x), std::fmax(a.x, b.x));
    y = rtx::Interval(std::fmin(a.y, b.y), std::fmax(a.y, b.y));
    z = rtx::Interval(std::fmin(a.z, b.z), std::fmax(a.z, b.z));
    padToMin();
}

rtx::BoundingBox::BoundingBox(const rtx::BoundingBox &a, const rtx::BoundingBox &b)
    : x(a.x, b.x)
    , y(a.y, b.y)
    , z(a.z, b.z)
{
}

void rtx::BoundingBox::padToMin()
{
    if (x.size() < 0.0001)
        x = x.expand(0.0001);
    if (y.size() < 0.0001)
        y = y.expand(0.0001);
    if (z.size() < 0.0001)
        z = z.expand(0.0001);
}

bool rtx::BoundingBox::hits(const rtx::Ray &ray, rtx::Interval rayT) const
{
    for (std::size_t i = 0; i < 3; ++i) {
        double invDir = 1.0 / ray.direction[i];
        double t0 = ((*this)[i].min - ray.origin[i]) * invDir;
        double t1 = ((*this)[i].max - ray.origin[i]) * invDir;

        if (t0 < t1) {
            if (t0 > rayT.min)
                rayT.min = t0;
            if (t1 < rayT.max)
                rayT.max = t1;
        } else {
            if (t1 > rayT.min)
                rayT.min = t1;
            if (t0 < rayT.max)
                rayT.max = t0;
        }
        if (rayT.max <= rayT.min)
            return false;
    }
    return true;
}

std::size_t rtx::BoundingBox::maxAxis() const
{
    if (x.size() > y.size())
        return x.size() > z.size() ? 0 : 2;
    return y.size() > z.size() ? 1 : 2;
}

const rtx::BoundingBox rtx::BoundingBox::empty = rtx::BoundingBox(rtx::Interval::empty, rtx::Interval::empty, rtx::Interval::empty);
const rtx::BoundingBox rtx::BoundingBox::universe = rtx::BoundingBox(rtx::Interval::universe, rtx::Interval::universe, rtx::Interval::universe);
