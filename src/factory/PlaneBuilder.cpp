/*
** EPITECH PROJECT, 2024
** PlaneBuilder.cpp
** File description:
** plane builder
*/

#include "PlaneBuilder.hpp"

rtx::PlaneBuilder::PlaneBuilder()
{
    reset();
}

std::shared_ptr<rtx::Plane> rtx::PlaneBuilder::getProduct()
{
    std::shared_ptr<rtx::Plane> product{_plane.release()};

    reset();
    product->update();
    return product;
}
