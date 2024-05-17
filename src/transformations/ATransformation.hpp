/*
** EPITECH PROJECT, 2024
** ATransformation.hpp
** File description:
** ITransformation abstract declaration
*/

#ifndef ATRANSFORMATION_HPP_
    #define ATRANSFORMATION_HPP_

    #include "ITransformation.hpp"
    #include "BoundingBox.hpp"

namespace rtx
{
    class ATransformation : public virtual rtx::ITransformation
    {
    protected:
        rtx::Vector3D _axis;
        rtx::BoundingBox _bBox;
        std::shared_ptr<rtx::IShape> _shape;

    public:
        virtual ~ATransformation() = default;

        virtual bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const = 0;
        virtual rtx::BoundingBox getBoundingBox() const override {return _bBox;}
    };
}

#endif /* !ATRANSFORMATION_HPP_ */
