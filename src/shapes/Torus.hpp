/*
** EPITECH PROJECT, 2024
** merge
** File description:
** Torus
*/

#ifndef TORUS_HPP_
#define TORUS_HPP_

#include "Vector3D.hpp"
#include "Ray.hpp"
#include "AShape.hpp"
#include "Interval.hpp"
#include "IMaterial.hpp"
#include <memory>

namespace rtx
{
    class Torus : public virtual rtx::AShape
    {
    public:
        Torus();
        Torus(rtx::Point3D center, double majorRadius, double minorRadius, std::shared_ptr<rtx::IMaterial> material);
        bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const override;

        void setMajorRadius(double majorRadius) {_majorRadius = majorRadius;}
        void setMinorRadius(double minorRadius) {_minorRadius = minorRadius;}
        void setCenter(const rtx::Point3D& center) {_center = center;}

    private:
        double _majorRadius;
        double _minorRadius;
        rtx::Point3D _center;
    };
}

#endif /* TORUS_HPP_ */
