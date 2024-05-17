/*
** EPITECH PROJECT, 2024
** AMaterial.hpp
** File description:
** IMaterial abstract declaration
*/

#ifndef AMATERIAL_HPP_
    #define AMATERIAL_HPP_

    #include "IMaterial.hpp"
    #include "Color.hpp"

namespace rtx
{
    class AMaterial : public virtual rtx::IMaterial
    {
        protected:
            rtx::Color _albedo;

        public:
            virtual ~AMaterial() = default;
            virtual bool reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const;
            virtual rtx::Color lightEmission(double u, double v, const rtx::Point3D& point) const;
    };
}

#endif
