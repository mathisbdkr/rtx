/*
** EPITECH PROJECT, 2024
** HitRecord.cpp
** File description:
** HitRecord
*/

#include "HitRecord.hpp"

void rtx::HitRecord::setFaceNormal(const rtx::Ray &ray, const rtx::Vector3D &outwardNormal)
{
    frontFace = ray.direction.dot(outwardNormal) < 0.0;
    normal = (frontFace == true) ? outwardNormal : outwardNormal * -1.0;
}
