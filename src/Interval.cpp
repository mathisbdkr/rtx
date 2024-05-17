/*
** EPITECH PROJECT, 2024
** Interval.cpp
** File description:
** interval class
*/

#include "Interval.hpp"
#include "macros.hpp"

rtx::Interval::Interval() : min(+infinity), max(-infinity) {}

rtx::Interval::Interval(double _min, double _max) : min(_min), max(_max) {}

rtx::Interval::Interval(const rtx::Interval &a, const rtx::Interval &b)
    : min(std::min(a.min, b.min))
    , max(std::max(a.max, b.max))
    {}

const rtx::Interval rtx::Interval::empty = rtx::Interval();
const rtx::Interval rtx::Interval::universe = rtx::Interval(-infinity, +infinity);

double rtx::Interval::clamp(double n) const
{
    if (n < min)
        return min;
    if (n > max)
        return max;
    return n;
}

rtx::Interval rtx::Interval::expand(double d) const
{
    double padding = d / 2.0;

    return rtx::Interval(min - padding, max + padding);
}
