/*
** EPITECH PROJECT, 2024
** Dielectric.cpp
** File description:
** transparent material
*/

#include "Dielectric.hpp"
#include "Vector3D.hpp"

rtx::Dielectric::Dielectric(double refractionIndex) : _refractionIndex(refractionIndex) {}

double rtx::Dielectric::reflectance(double cosine, double refractionIndex) const
{
    double ref = pow((1.0 - refractionIndex) / (1.0 + refractionIndex), 2);

    return ref + (1.0 - ref) * pow((1.0 - cosine), 5);
}

bool rtx::Dielectric::reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const
{
    double ri = rec.frontFace ? (1.0 / _refractionIndex) : _refractionIndex;
    rtx::Vector3D unitDir = rayIn.direction.unitVector();
    double cosTheta = fmin((unitDir * (-1.0)).dot(rec.normal), 1.0);
    double sinTheta = sqrt(1.0 - (cosTheta * cosTheta));
    rtx::Vector3D dir;

    if ((ri * sinTheta) > 1.0 || reflectance(cosTheta, ri) > randomValue())
        dir = unitDir.reflect(rec.normal);
    else
        dir = unitDir.refract(rec.normal, ri);
    attenuation = rtx::Color(1.0, 1.0, 1.0);
    reflected = rtx::Ray(rec.point, dir, rayIn.time);
    return true;
}
