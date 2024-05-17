/*
** EPITECH PROJECT, 2024
** BoundingVolume.cpp
** File description:
** bounding volume hierarchy
*/

#include "BoundingVolume.hpp"
#include "macros.hpp"
#include <algorithm>
#include <functional>

rtx::BoundingVolume::BoundingVolume(std::vector<std::shared_ptr<rtx::IShape>> &shapes, std::size_t start, std::size_t end)
{
    _bBox = rtx::BoundingBox::empty;
    for (std::size_t i = start; i < end; ++i)
        _bBox = rtx::BoundingBox(_bBox, shapes[i]->getBoundingBox());
    std::size_t axis = _bBox.maxAxis();

    std::function<bool(const std::shared_ptr<rtx::IShape>, const std::shared_ptr<rtx::IShape>)> comparator;
    std::size_t range = end - start;

    switch (axis) {
    case 0:
        comparator = compareBoxesX;
        break;
    case 1:
        comparator = compareBoxesY;
        break;
    default:
        comparator = compareBoxesZ;
        break;
    }

    if (range == 1) {
        _right = shapes[start];
        _left = _right;
    } else if (range == 2) {
        _left = shapes[start];
        _right = shapes[start + 1];
    } else {
        std::sort(shapes.begin() + start, shapes.begin() + end, comparator);
        std::size_t mid = start + range / 2;

        _left = std::make_shared<rtx::BoundingVolume>(shapes, start, mid);
        _right = std::make_shared<rtx::BoundingVolume>(shapes, mid, end);
    }
}

rtx::BoundingVolume::BoundingVolume(rtx::Scene scene)
    : BoundingVolume(scene.shapes, 0, scene.shapes.size())
{
}

bool rtx::BoundingVolume::hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const
{
    if (_bBox.hits(ray, rayT) == false)
        return false;
    bool leftHits = _left->hits(ray, rayT, rec);
    bool rightHits = _right->hits(ray, rtx::Interval(rayT.min, leftHits ? rec.t : rayT.max), rec);
    return leftHits || rightHits;
}
