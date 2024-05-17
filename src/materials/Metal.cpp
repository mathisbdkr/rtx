/*
** EPITECH PROJECT, 2024
** Metal.cpp
** File description:
** metal material
*/

#include "Metal.hpp"

rtx::Metal::Metal(const rtx::Color &albedo, double grain)
    : _grain(grain < 1.0 ? grain : 1.0)
{
    _albedo = albedo;
}

bool rtx::Metal::reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const
{
    rtx::Vector3D reflectedRayIn = rayIn.direction.reflect(rec.normal).unitVector() + (rtx::Vector3D::randomUnitVector() * _grain);

    reflected = rtx::Ray(rec.point, reflectedRayIn, rayIn.time);
    attenuation = _albedo;
    return reflected.direction.dot(rec.normal) > 0.0;
}
