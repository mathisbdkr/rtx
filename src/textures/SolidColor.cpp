/*
** EPITECH PROJECT, 2024
** backup
** File description:
** SolidColor
*/

#include "SolidColor.hpp"

rtx::SolidColor::SolidColor(const rtx::Color& albedo)
{
    _albedo = albedo;
}

rtx::SolidColor::SolidColor(double r, double g, double b)
{
    SolidColor(rtx::Color(r,g,b));
}

rtx::Color rtx::SolidColor::textureColor(double u, double v, const rtx::Point3D& p) const
{
    return _albedo;
}
