/*
** EPITECH PROJECT, 2024
** CylinderBuilder.cpp
** File description:
** cylinder builder
*/

#include "CylinderBuilder.hpp"

rtx::CylinderBuilder::CylinderBuilder()
{
    reset();
}

std::shared_ptr<rtx::Cylinder> rtx::CylinderBuilder::getProduct()
{
    std::shared_ptr<rtx::Cylinder> product{_cylinder.release()};

    reset();
    return product;
}
