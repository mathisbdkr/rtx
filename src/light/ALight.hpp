/*
** EPITECH PROJECT, 2024
** merge
** File description:
** ALight
*/

#ifndef ALIGHT_HPP_
    #define ALIGHT_HPP_

    #include "ILight.hpp"
    #include "Color.hpp"

namespace rtx
{
    class ALight : public virtual rtx::ILight
    {
        protected:
            rtx::Color _albedo;

        public:
            virtual ~ALight() = default;

            bool reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const override;
            virtual rtx::Color lightEmission(double u, double v, const rtx::Point3D& point) const override;
            virtual rtx::Color ambientLight(double ambient, rtx::Color& actualColor, rtx::Color& defaultColor) const override;
    };
}

#endif /* !ALIGHT_HPP_ */
