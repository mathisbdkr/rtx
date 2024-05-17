/*
** EPITECH PROJECT, 2024
** TriangleBuilder.cpp
** File description:
** triangle builder
*/

#include "TriangleBuilder.hpp"

rtx::TriangleBuilder::TriangleBuilder()
{
    reset();
}

std::shared_ptr<rtx::Triangle> rtx::TriangleBuilder::getProduct()
{
    std::shared_ptr<rtx::Triangle> product{_triangle.release()};

    reset();
    return product;
}
