/*
** EPITECH PROJECT, 2024
** Translation.hpp
** File description:
** translation of rays
*/

#ifndef TRANSLATION_HPP_
    #define TRANSLATION_HPP_

    #include "ATransformation.hpp"
    #include "Ray.hpp"
    #include "Interval.hpp"
    #include "HitRecord.hpp"
    #include "Vector3D.hpp"
    #include <memory>

namespace rtx
{
    class Translation : public virtual rtx::ATransformation
    {
    public:
        Translation() = delete;
        Translation(std::shared_ptr<rtx::IShape> shape, const rtx::Vector3D &axis);
        ~Translation() = default;

        bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const override;
    };
}

#endif
