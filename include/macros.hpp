/*
** EPITECH PROJECT, 2024
** macros.hpp
** File description:
** macros for raytracer
*/

#ifndef MACROS_HPP_
    #define MACROS_HPP_

    #include <limits>
    #include <cmath>

const double infinity = std::numeric_limits<double>::infinity();

inline double degToRad(double deg)
{
    return deg * M_PI / 180.0f;
}

inline double randomValue()
{
    return rand() / (RAND_MAX + 1.0f);
}

inline double randomValue(double min, double max)
{
    return min + (max - min) * randomValue();
}

inline int randomTwoInt(int min, int max)
{
    return int(randomValue(min, max+1));
}

#endif
