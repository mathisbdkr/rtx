/*
** EPITECH PROJECT, 2024
** Dielectric.hpp
** File description:
** transparent material
*/

#ifndef DIELECTRIC_HPP_
    #define DIELECTRIC_HPP_

    #include "AMaterial.hpp"
    #include "Color.hpp"

namespace rtx
{
    class Dielectric : public virtual rtx::AMaterial
    {
    private:
        double _refractionIndex;

        double reflectance(double cosine, double refractionIndex) const;

    public:
        Dielectric(double refractionIndex);
        ~Dielectric() = default;

        bool reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const override;
    };
}

#endif
