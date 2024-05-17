/*
** EPITECH PROJECT, 2024
** Color.cpp
** File description:
** color class
*/

#include "Color.hpp"

rtx::Color::Color() : rtx::Vector3D()
{
}

rtx::Color::Color(double x, double y, double z) : rtx::Vector3D(x, y, z)
{
}

rtx::Color::Color(const rtx::Color &other) : rtx::Vector3D(other)
{
}

rtx::Color::Color(const rtx::Vector3D &other) : rtx::Vector3D(other)
{
}

rtx::Color::Color(rtx::Vector3D &&other) : rtx::Vector3D(other)
{
}

std::ostream &operator<<(std::ostream &out, const rtx::Color &color)
{
    return out << short(color.x) << ' ' << short(color.y) << ' ' << short(color.z);
}

double rtx::Color::toGamma(double val)
{
    if (val > 0.0)
        return sqrt(val);
    return 0.0;
}

void rtx::Color::smoothenPixels(const rtx::Interval &intensity)
{
    x = short(256.0 * intensity.clamp(x));
    y = short(256.0 * intensity.clamp(y));
    z = short(256.0 * intensity.clamp(z));
}

void rtx::Color::correctGamma()
{
    x = toGamma(x);
    y = toGamma(y);
    z = toGamma(z);
}
