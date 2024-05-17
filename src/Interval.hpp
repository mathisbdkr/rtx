/*
** EPITECH PROJECT, 2024
** Interval.hpp
** File description:
** interval class
*/

#ifndef INTERVAL_HPP_
    #define INTERVAL_HPP_

namespace rtx
{
    class Interval
    {
    public:
        Interval();
        Interval(double _min, double _max);
        Interval(const rtx::Interval &a, const rtx::Interval &b);
        ~Interval() = default;

        rtx::Interval operator+(double n) const
        {
            return rtx::Interval(min + n, max + n);
        }
        rtx::Interval &operator+=(double n)
        {
            min += n;
            max += n;
            return *this;
        }
        rtx::Interval operator-(double n) const
        {
            return rtx::Interval(min - n, max - n);
        }
        rtx::Interval &operator-=(double n)
        {
            min -= n;
            max -= n;
            return *this;
        }
        rtx::Interval operator*(double n) const
        {
            return rtx::Interval(min * n, max * n);
        }
        rtx::Interval &operator*=(double n)
        {
            min *= n;
            max *= n;
            return *this;
        }
        rtx::Interval operator/(double n) const
        {
            return rtx::Interval(min / n, max / n);
        }
        rtx::Interval &operator/=(double n)
        {
            min /= n;
            max /= n;
            return *this;
        }

        double min;
        double max;

        double size() const {return max - min;}
        bool contains(double n) const {return n >= min && n <= max;}
        bool surrounds(double n) const {return n > min && n < max;}
        double clamp(double n) const;
        rtx::Interval expand(double d) const;

        static const rtx::Interval empty;
        static const rtx::Interval universe;
    };
}


#endif
