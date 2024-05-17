/*
** EPITECH PROJECT, 2024
** Ray.hpp
** File description:
** ray class
*/

#ifndef RAY_HPP_
    #define RAY_HPP_

    #include "Vector3D.hpp"
    #include <memory>

namespace rtx
{
    class Ray
    {
    public:
        Ray();
        Ray(rtx::Point3D origin, rtx::Vector3D direction);
        Ray(rtx::Point3D origin, rtx::Vector3D direction, double time);
        Ray(const Ray &other);
        Ray(Ray &&other) = default;
        ~Ray() = default;

        Ray &operator=(const Ray &other)
        {
            origin = other.origin;
            direction = other.direction;
            return *this;
        }
        Ray &operator=(Ray &&other)
        {
            origin = std::move(other.origin);
            direction = std::move(other.direction);
            return *this;
        }

        rtx::Point3D origin;
        rtx::Vector3D direction;
        double time;

        rtx::Point3D at(double t) const;
    };
}

#endif
