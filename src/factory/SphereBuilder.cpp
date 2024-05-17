/*
** EPITECH PROJECT, 2024
** SphereBuilder.cpp
** File description:
** sphere builder
*/

#include "SphereBuilder.hpp"

rtx::SphereBuilder::SphereBuilder()
{
    reset();
}

std::shared_ptr<rtx::Sphere> rtx::SphereBuilder::getProduct()
{
    std::shared_ptr<rtx::Sphere> product{_sphere.release()};

    reset();
    return product;
}
