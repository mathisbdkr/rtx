/*
** EPITECH PROJECT, 2024
** Vector3D.hpp
** File description:
** 3d vector
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_

    #include <memory>
    #include <cmath>
    #include <ostream>
    #include "macros.hpp"

namespace rtx
{
    class Vector3D
    {
    public:
        Vector3D();
        Vector3D(double x, double y, double z);
        Vector3D(const Vector3D &other);
        Vector3D(Vector3D &&other) = default;
        ~Vector3D() = default;

        double &operator[](std::size_t i)
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
        double operator[](std::size_t i) const
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
        Vector3D operator-() const {return Vector3D(-x, -y, -z);}
        Vector3D &operator=(const Vector3D &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
        Vector3D &operator=(Vector3D &&other)
        {
            x = std::move(other.x);
            y = std::move(other.y);
            z = std::move(other.z);
            return *this;
        }
        Vector3D operator+(const Vector3D &other) const
        {
            return Vector3D(x + other.x, y + other.y, z + other.z);
        }
        Vector3D operator+(double n) const
        {
            return Vector3D(x + n, y + n, z + n);
        }
        Vector3D &operator+=(const Vector3D &other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }
        Vector3D &operator+=(double n)
        {
            x += n;
            y += n;
            z += n;
            return *this;
        }
        Vector3D operator-(const Vector3D &other) const
        {
            return Vector3D(x - other.x, y - other.y, z - other.z);
        }
        Vector3D operator-(double n) const
        {
            return Vector3D(x - n, y - n, z - n);
        }
        Vector3D &operator-=(const Vector3D &other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }
        Vector3D &operator-=(double n)
        {
            x -= n;
            y -= n;
            z -= n;
            return *this;
        }
        Vector3D operator*(const Vector3D &other) const
        {
            return Vector3D(x * other.x, y * other.y, z * other.z);
        }
        Vector3D operator*(double n) const
        {
            return Vector3D(x * n, y * n, z * n);
        }
        Vector3D &operator*=(const Vector3D &other)
        {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            return *this;
        }
        Vector3D &operator*=(double n)
        {
            x *= n;
            y *= n;
            z *= n;
            return *this;
        }
        Vector3D operator/(const Vector3D &other) const
        {
            return Vector3D(x / other.x, y / other.y, z / other.z);
        }
        Vector3D operator/(double n) const
        {
            return Vector3D(x / n, y / n, z / n);
        }
        Vector3D &operator/=(const Vector3D &other)
        {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            return *this;
        }
        Vector3D &operator/=(double n)
        {
            x /= n;
            y /= n;
            z /= n;
            return *this;
        }

        Vector3D cross(const Vector3D& v) const
        {
            return Vector3D(y * v.z - z * v.y,
                        z * v.x - x * v.z,
                        x * v.y - y * v.x);
        }

        double x;
        double y;
        double z;

        double length() const {return sqrt(dot(*this));}
        double lengthSquared() const {return dot(*this);}
        double dot(const rtx::Vector3D &other) const {return x * other.x + y * other.y + z * other.z;}
        rtx::Vector3D unitVector() const {return *this / length();}
        bool closeToZero() const;
        rtx::Vector3D reflect(const rtx::Vector3D &other) const {return *this - (other * (2 * dot(other)));}
        rtx::Vector3D refract(const rtx::Vector3D &other, double etaIOverEtaT);

        static rtx::Vector3D randomInUnitDisk();
        static rtx::Vector3D randomVectInSphere();
        static rtx::Vector3D randomVectOnSphere(const rtx::Vector3D &normal);
        static rtx::Vector3D randomUnitVector() {return rtx::Vector3D::randomVectInSphere().unitVector();}
        static rtx::Vector3D random() {return rtx::Vector3D(randomValue(), randomValue(), randomValue());}
        static rtx::Vector3D random(double min, double max) {return rtx::Vector3D(randomValue(min, max), randomValue(min, max), randomValue(min, max));}
    };

    using Point3D = Vector3D;
}

std::ostream &operator<<(std::ostream &out, const rtx::Vector3D &vect);

#endif
