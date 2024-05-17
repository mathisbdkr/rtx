/*
** EPITECH PROJECT, 2024
** Color.hpp
** File description:
** color class
*/

#ifndef COLOR_HPP_
    #define COLOR_HPP_

    #include "Vector3D.hpp"
    #include "Interval.hpp"
    #include <ostream>

namespace rtx
{
    class Color : public virtual rtx::Vector3D
    {
    private:
        double toGamma(double linear);

    public:
        Color();
        Color(double x, double y, double z);
        Color(const Color &other);
        Color(const rtx::Vector3D &other);
        Color(rtx::Vector3D &&other);
        Color(Color &&other) = default;
        ~Color() = default;

        Color &operator=(const Color &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
        Color &operator=(Color &&other)
        {
            x = std::move(other.x);
            y = std::move(other.y);
            z = std::move(other.z);
            return *this;
        }
        Color &operator=(const rtx::Vector3D &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
        Color &operator=(rtx::Vector3D &&other)
        {
            x = std::move(other.x);
            y = std::move(other.y);
            z = std::move(other.z);
            return *this;
        }

        void smoothenPixels(const rtx::Interval &interval);
        void correctGamma();
    };
}

std::ostream &operator<<(std::ostream &out, const rtx::Color &vect);

#endif
