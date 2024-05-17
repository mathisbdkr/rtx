/*
** EPITECH PROJECT, 2024
** backup
** File description:
** Light
*/

#include "Light.hpp"
#include "iostream"
#include "Rotation.hpp"

rtx::Light::Light(std::shared_ptr<rtx::ITexture> tex)
{
    _texture = tex;
}

rtx::Light::Light(const rtx::Color& emit)
{
    _texture = std::make_shared<rtx::SolidColor>(emit);
}

rtx::Color rtx::Light::lightEmission(double u, double v, const rtx::Point3D& point) const
{
    return _texture->textureColor(u, v, point);
}

rtx::Color rtx::Light::ambientLight(double ambient, rtx::Color& actualColor, rtx::Color& defaultColor) const {
    if (actualColor.x == 0.00 && actualColor.y == 0.00 && actualColor.z == 0.00) {
        actualColor.x = defaultColor.x * ambient;
        actualColor.y = defaultColor.y * ambient;
        actualColor.z = defaultColor.z * ambient;
    }
    return actualColor;
}
