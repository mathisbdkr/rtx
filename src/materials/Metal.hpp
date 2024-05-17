/*
** EPITECH PROJECT, 2024
** Metal.hpp
** File description:
** metal material
*/

#ifndef METAL_HPP_
    #define METAL_HPP_

    #include "AMaterial.hpp"
    #include "Color.hpp"

namespace rtx
{
    class Metal : public virtual rtx::AMaterial
    {
    private:
        double _grain;

    public:
        Metal(const rtx::Color &albedo, double grain);
        ~Metal() = default;

        bool reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const override;
    };
}

#endif
