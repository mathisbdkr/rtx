/*
** EPITECH PROJECT, 2024
** BoundingBox.hpp
** File description:
** axis aligned bounding box
*/

#ifndef BOUNDINGBOX_HPP_
    #define BOUNDINGBOX_HPP_

    #include "Interval.hpp"
    #include "Vector3D.hpp"
    #include "Ray.hpp"

namespace rtx
{
    class BoundingBox
    {
    private:
        void padToMin();

    public:
        BoundingBox();
        BoundingBox(const rtx::Interval &x, const rtx::Interval &y, const rtx::Interval &z);
        BoundingBox(const rtx::Point3D &a, const rtx::Point3D &b);
        BoundingBox(const rtx::BoundingBox &a, const rtx::BoundingBox &b);
        ~BoundingBox() = default;

        rtx::Interval x;
        rtx::Interval y;
        rtx::Interval z;

        const rtx::Interval &operator[](std::size_t i) const
        {
            switch (i) {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            default:
                throw std::out_of_range("Invalid index " + std::to_string(i));
            }
        }
        rtx::Interval &operator[](std::size_t i)
        {
            switch (i) {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            default:
                throw std::out_of_range("Invalid index " + std::to_string(i));
            }
        }
        rtx::BoundingBox operator+(const rtx::Vector3D &vect) const
        {
            return rtx::BoundingBox(x + vect.x, y + vect.y, z + vect.z);
        }
        rtx::BoundingBox &operator+=(const rtx::Vector3D &vect)
        {
            x += vect.x;
            y += vect.y;
            z += vect.z;
            return *this;
        }
        rtx::BoundingBox operator+(double n) const
        {
            return rtx::BoundingBox(x + n, y + n, z + n);
        }
        rtx::BoundingBox &operator+=(double n)
        {
            x += n;
            y += n;
            z += n;
            return *this;
        }
        rtx::BoundingBox operator-(const rtx::Vector3D &vect) const
        {
            return rtx::BoundingBox(x - vect.x, y - vect.y, z - vect.z);
        }
        rtx::BoundingBox &operator-=(const rtx::Vector3D &vect)
        {
            x -= vect.x;
            y -= vect.y;
            z -= vect.z;
            return *this;
        }
        rtx::BoundingBox operator-(double n) const
        {
            return rtx::BoundingBox(x - n, y - n, z - n);
        }
        rtx::BoundingBox &operator-=(double n)
        {
            x -= n;
            y -= n;
            z -= n;
            return *this;
        }
        rtx::BoundingBox operator*(const rtx::Vector3D &vect) const
        {
            return rtx::BoundingBox(x * vect.x, y * vect.y, z * vect.z);
        }
        rtx::BoundingBox &operator*=(const rtx::Vector3D &vect)
        {
            x *= vect.x;
            y *= vect.y;
            z *= vect.z;
            return *this;
        }
        rtx::BoundingBox operator*(double n) const
        {
            return rtx::BoundingBox(x * n, y * n, z * n);
        }
        rtx::BoundingBox &operator*=(double n)
        {
            x *= n;
            y *= n;
            z *= n;
            return *this;
        }
        rtx::BoundingBox operator/(const rtx::Vector3D &vect) const
        {
            return rtx::BoundingBox(x / vect.x, y / vect.y, z / vect.z);
        }
        rtx::BoundingBox &operator/=(const rtx::Vector3D &vect)
        {
            x /= vect.x;
            y /= vect.y;
            z /= vect.z;
            return *this;
        }
        rtx::BoundingBox operator/(double n) const
        {
            return rtx::BoundingBox(x / n, y / n, z / n);
        }
        rtx::BoundingBox &operator/=(double n)
        {
            x /= n;
            y /= n;
            z /= n;
            return *this;
        }

        bool hits(const rtx::Ray &ray, rtx::Interval rayT) const;
        std::size_t maxAxis() const;

        static const rtx::BoundingBox empty;
        static const rtx::BoundingBox universe;
    };
}

#endif
