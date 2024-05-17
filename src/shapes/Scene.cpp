/*
** EPITECH PROJECT, 2024
** Scene.cpp
** File description:
** list of shapes
*/

#include "Scene.hpp"
#include "IShape.hpp"
#include "HitRecord.hpp"
#include "Interval.hpp"
#include "BoundingBox.hpp"
#include <memory>

rtx::Scene::Scene() {}

rtx::Scene::Scene(std::shared_ptr<rtx::IShape> shape)
{
    add(shape);
}

bool rtx::Scene::hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const
{
    rtx::HitRecord tmpRec;
    bool hitsShape = false;
    double closest = rayT.max;

    for (const auto &shape : shapes) {
        if (shape->hits(ray, rtx::Interval(rayT.min, closest), tmpRec)) {
            hitsShape = true;
            closest = tmpRec.t;
            rec = tmpRec;
        }
    }
    return hitsShape;
}

void rtx::Scene::add(std::shared_ptr<rtx::IShape> shape)
{
    shapes.push_back(shape);
    _bBox = rtx::BoundingBox(_bBox, shape->getBoundingBox());
}

void rtx::Scene::add(rtx::Scene &scene)
{
    for (auto &shape : scene.shapes)
        add(shape);
}
