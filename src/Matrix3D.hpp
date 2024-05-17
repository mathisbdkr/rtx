/*
** EPITECH PROJECT, 2024
** Matrix3D.hpp
** File description:
** matrix with 3 dimensions
*/

#ifndef MATRIX3D_HPP_
    #define MATRIX3D_HPP_

    #include <memory>
    #include "Vector3D.hpp"

namespace rtx
{
    class Matrix3D
    {
    public:
        Matrix3D();
        Matrix3D(rtx::Vector3D x, rtx::Vector3D y, rtx::Vector3D z);
        Matrix3D(const Matrix3D &other);
        Matrix3D(Matrix3D &&other) = default;
        ~Matrix3D() = default;

        rtx::Vector3D x;
        rtx::Vector3D y;
        rtx::Vector3D z;

        rtx::Vector3D &operator[](std::size_t i)
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
        rtx::Vector3D operator[](std::size_t i) const
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
        Matrix3D operator-() const {return Matrix3D(-x, -y, -z);}
        Matrix3D &operator=(const Matrix3D &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
        Matrix3D &operator=(Matrix3D &&other)
        {
            x = std::move(other.x);
            y = std::move(other.y);
            z = std::move(other.z);
            return *this;
        }
        Matrix3D operator*(const Matrix3D &other) const
        {
            rtx::Matrix3D res;

            for (std::size_t i = 0; i < 3; ++i) {
                for (std::size_t j = 0; j < 3; ++j) {
                    for (std::size_t k = 0; k < 3; ++k)
                        res[i][j] += (*this)[i][k] * other[k][j];
                }
            }
            return res;
        }
        Matrix3D &operator*=(const Matrix3D &other)
        {
            *this = *this * other;
            return *this;
        }
        rtx::Vector3D operator*(const rtx::Vector3D &other) const
        {
            rtx::Vector3D res;

            for (std::size_t i = 0; i < 3; ++i) {
                for (std::size_t j = 0; j < 3; ++j)
                    res[i] += (*this)[i][j] * other[j];
            }
            return res;
        }
    };
}

#endif
