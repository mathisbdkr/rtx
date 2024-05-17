/*
** EPITECH PROJECT, 2024
** IMaterial.hpp
** File description:
** material interface
*/

#ifndef IMATERIAL_HPP_
    #define IMATERIAL_HPP_

namespace rtx
{
    class HitRecord;
}

    #include "Ray.hpp"
    #include "HitRecord.hpp"
    #include "Vector3D.hpp"
    #include "Color.hpp"

namespace rtx
{
    class IMaterial
    {
    public:
        virtual ~IMaterial() = default;

        virtual bool reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const = 0;
        virtual rtx::Color lightEmission(double u, double v, const rtx::Point3D& point) const = 0;
    };
}

#endif
