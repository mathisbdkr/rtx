/*
** EPITECH PROJECT, 2024
** ConeBuilder.cpp
** File description:
** cone builder
*/

#include "ConeBuilder.hpp"

rtx::ConeBuilder::ConeBuilder()
{
    reset();
}

std::shared_ptr<rtx::Cone> rtx::ConeBuilder::getProduct()
{
    std::shared_ptr<rtx::Cone> product{_cone.release()};

    reset();
    return product;
}
