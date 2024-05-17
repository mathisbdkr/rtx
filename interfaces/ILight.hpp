/*
** EPITECH PROJECT, 2024
** merge
** File description:
** ILight
*/

#ifndef ILIGHT_HPP_
    #define ILIGHT_HPP_

    #include "Vector3D.hpp"
    #include "IMaterial.hpp"
    #include "Color.hpp"

namespace rtx
{
    class ILight : public virtual rtx::IMaterial {
        public:
            virtual ~ILight() = default;

            virtual bool reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const = 0;
            virtual rtx::Color lightEmission(double u, double v, const rtx::Point3D& point) const = 0;
            virtual rtx::Color ambientLight(double ambient, rtx::Color& actualColor, rtx::Color& defaultColor) const = 0;
    };
}

#endif /* !ILIGHT_HPP_ */
