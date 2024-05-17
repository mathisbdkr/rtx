/*
** EPITECH PROJECT, 2024
** Matte.cpp
** File description:
** matte material
*/

#include "Matte.hpp"
#include "Vector3D.hpp"

rtx::Matte::Matte(const rtx::Color &albedo)
{
    texture = std::make_shared<SolidColor>(albedo);
}

rtx::Matte::Matte(std::shared_ptr<ITexture> tex)
{
    texture = tex;
}

bool rtx::Matte::reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const
{
    rtx::Vector3D reflectDir = rec.normal + rtx::Vector3D::randomUnitVector();

    if (reflectDir.closeToZero())
        reflectDir = rec.normal;
    reflected = rtx::Ray(rec.point, reflectDir, rayIn.time);
    attenuation = texture->textureColor(rec.u, rec.v, rec.point);
    return true;
}
