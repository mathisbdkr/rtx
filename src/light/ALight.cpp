/*
** EPITECH PROJECT, 2024
** rtx
** File description:
** ALight
*/

#include "ALight.hpp"

bool rtx::ALight::reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const
{
    return false;
}

rtx::Color rtx::ALight::lightEmission(double u, double v, const rtx::Point3D& point) const
{
    return rtx::Color(0,0,0);
}

rtx::Color rtx::ALight::ambientLight(double ambient, rtx::Color& actualColor, rtx::Color& defaultColor) const
{
    if (actualColor.x == 0.0 && actualColor.y == 0.0 && actualColor.z == 0.0) {
        actualColor.x = defaultColor.x * ambient;
        actualColor.y = defaultColor.y * ambient;
        actualColor.z = defaultColor.z * ambient;
    }
    return actualColor;
}
