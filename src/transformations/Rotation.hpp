/*
** EPITECH PROJECT, 2024
** Rotation.hpp
** File description:
** rotation of rays
*/

#ifndef ROTATION_HPP_
    #define ROTATION_HPP_

    #include "ATransformation.hpp"
    #include "Ray.hpp"
    #include "Interval.hpp"
    #include "HitRecord.hpp"
    #include "Vector3D.hpp"
    #include "Matrix3D.hpp"
    #include <memory>

namespace rtx
{
    class Rotation : public virtual rtx::ATransformation
    {
    private:
        rtx::Matrix3D _rotationMatrix;
        double _theta;

        rtx::Matrix3D getRotationMatrix(std::size_t axis) const;
        rtx::Matrix3D getInvertedRotationMatrix(std::size_t axis) const;

    public:
        Rotation() = delete;
        Rotation(std::shared_ptr<rtx::IShape> shape, const rtx::Vector3D &axis, double angle);
        ~Rotation() = default;

        bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const override;
    };
}

#endif
