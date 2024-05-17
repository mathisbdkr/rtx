/*
** EPITECH PROJECT, 2024
** Vector3D.cpp
** File description:
** 3d vector
*/

#include "Vector3D.hpp"
#include <memory>

rtx::Vector3D::Vector3D()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    {}

rtx::Vector3D::Vector3D(double x, double y, double z)
    : x(x)
    , y(y)
    , z(z)
    {}

rtx::Vector3D::Vector3D(const rtx::Vector3D &other)
    : x(other.x)
    , y(other.y)
    , z(other.z)
    {}

rtx::Vector3D rtx::Vector3D::randomVectInSphere()
{
    rtx::Vector3D point;

    do {
        point = rtx::Vector3D::random(-1.0, 1.0);
    } while (point.lengthSquared() >= 1.0);
    return point;
}

rtx::Vector3D rtx::Vector3D::randomVectOnSphere(const rtx::Vector3D &normal)
{
    rtx::Vector3D randomUnitVect = rtx::Vector3D::randomUnitVector();

    if (randomUnitVect.dot(normal) > 0.0)
        return randomUnitVect;
    return -randomUnitVect;
}

bool rtx::Vector3D::closeToZero() const
{
    static const double tolerance = 0.00000001;

    return (std::fabs(x) < tolerance) && (std::fabs(y) < tolerance) && (std::fabs(z) < tolerance);
}

rtx::Vector3D rtx::Vector3D::refract(const rtx::Vector3D &other, double etaIOverEtaT)
{
    double cosTheta = std::fmin(-(*this).dot(other), 1.0);
    rtx::Vector3D rayOutPerPoint = ((other * cosTheta) + *this) * etaIOverEtaT;
    rtx::Vector3D rayOutParallel = other * (-sqrt(std::fabs(rayOutPerPoint.lengthSquared() - 1.0)));

    return rayOutPerPoint + rayOutParallel;
}

rtx::Vector3D rtx::Vector3D::randomInUnitDisk()
{
    rtx::Vector3D vect;

    do {
        vect = rtx::Vector3D(randomValue(-1.0, 1.0), randomValue(-1.0, 1.0), 0.0);
    } while (vect.lengthSquared() >= 1.0);
    return vect;
}

std::ostream &operator<<(std::ostream &out, const rtx::Vector3D &vect)
{
    return out << '(' << vect.x << ", " << vect.y << ", " << vect.z << ')';
}
