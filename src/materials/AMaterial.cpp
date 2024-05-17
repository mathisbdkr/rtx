/*
** EPITECH PROJECT, 2024
** AMaterial.cpp
** File description:
** IMaterial abstract implementation
*/

#include "AMaterial.hpp"

bool rtx::AMaterial::reflect(const rtx::Ray &rayIn, const rtx::HitRecord &rec, rtx::Color &attenuation, rtx::Ray &reflected) const
{
    return false;
}

rtx::Color rtx::AMaterial::lightEmission(double u, double v, const rtx::Point3D& point) const
{
    return rtx::Color(0,0,0);
}