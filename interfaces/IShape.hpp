/*
** EPITECH PROJECT, 2024
** Shape.hpp
** File description:
** Shape interface class
*/

#ifndef SHAPE_HPP_
    #define SHAPE_HPP_

    #include "Ray.hpp"
    #include "HitRecord.hpp"
    #include "Interval.hpp"
    #include "BoundingBox.hpp"

namespace rtx
{
    class IShape
    {
    public:
        virtual ~IShape() = default;

        virtual bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const = 0;
        virtual rtx::BoundingBox getBoundingBox() const = 0;
    };
}

#endif
