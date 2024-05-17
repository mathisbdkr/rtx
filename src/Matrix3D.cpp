/*
** EPITECH PROJECT, 2024
** Matrix3D.cpp
** File description:
** matrix 3d
*/

#include "Matrix3D.hpp"

rtx::Matrix3D::Matrix3D()
    : x()
    , y()
    , z()
    {}

rtx::Matrix3D::Matrix3D(rtx::Vector3D _x, rtx::Vector3D _y, rtx::Vector3D _z)
    : x(_x)
    , y(_y)
    , z(_z)
    {}

rtx::Matrix3D::Matrix3D(const rtx::Matrix3D &other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    {}
