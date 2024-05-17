/*
** EPITECH PROJECT, 2024
** Matte.hpp
** File description:
** matte material
*/

#ifndef MATTE_HPP_
    #define MATTE_HPP_

    #include "AMaterial.hpp"
    #include "ITexture.hpp"
    #include "Vector3D.hpp"
    #include "SolidColor.hpp"

namespace rtx
{
    class Matte : public virtual rtx::AMaterial
    {
    public:
        Matte(const rtx::Color &albedo);
        Matte(std::shared_ptr<ITexture> tex);
        ~Matte() = default;

        bool reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const override;
    private:
        std::shared_ptr<ITexture> texture;
    };
}

#endif
