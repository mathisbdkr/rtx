/*
** EPITECH PROJECT, 2024
** Box.hpp
** File description:
** box shape
*/

#ifndef BOX_HPP_
    #define BOX_HPP_

    #include "IShape.hpp"
    #include "AShape.hpp"
    #include "Scene.hpp"
    #include <memory>

namespace rtx
{
    class Box : public virtual rtx::AShape
    {
    private:
        rtx::Scene _sides;

    public:
        Box(const rtx::Point3D &a, const rtx::Point3D &b, std::shared_ptr<rtx::IMaterial> material);
        ~Box() = default;

        bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const override;
    };
}

#endif
