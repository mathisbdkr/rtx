/*
** EPITECH PROJECT, 2024
** AShape.hpp
** File description:
** Abstract implementation for IShape
*/

#ifndef ASHAPE_HPP_
    #define ASHAPE_HPP_

    #include "IShape.hpp"
    #include "IMaterial.hpp"
    #include "Vector3D.hpp"
    #include "BoundingBox.hpp"
    #include <memory>

namespace rtx
{
    class AShape : public virtual rtx::IShape
    {
    protected:
        rtx::BoundingBox _bBox;

    public:
        virtual ~AShape() = default;

        rtx::Point3D center;
        std::shared_ptr<rtx::IMaterial> _material;

        virtual bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const = 0;
        virtual rtx::BoundingBox getBoundingBox() const override {return _bBox;}
    };
}

#endif
