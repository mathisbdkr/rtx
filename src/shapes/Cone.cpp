/*
** EPITECH PROJECT, 2024
** rtx
** File description:
** Cone
*/

#include "Cone.hpp"

rtx::Cone::Cone() : _radius(1.0), _height(1.0)
{
    center = rtx::Point3D();
    _material = nullptr;
}

rtx::Cone::Cone(rtx::Point3D center, double radius, double height, std::shared_ptr<rtx::IMaterial> material) : _radius(radius), _height(height)
{
    this->center = center;
    _material = material;
}

bool rtx::Cone::hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const
{
    rtx::Vector3D diff = ray.origin - center;
    double k = _radius / _height;
    double a = std::pow(ray.direction.x, 2) + std::pow(ray.direction.z, 2) - (std::pow(k, 2) * std::pow(ray.direction.y, 2));
    double b = 2 * ((ray.direction.x * diff.x) + (ray.direction.z * diff.z) - (std::pow(k, 2) * ray.direction.y * (ray.origin.y - center.y)));
    double c = std::pow(diff.x, 2) + std::pow(diff.z, 2) - (std::pow(k, 2) * std::pow(diff.y, 2));
    double d = (b * b) - 4 * (a * c);

    if (d < 0.0)
        return false;

    double root = (-b - std::sqrt(d)) / (2 * a);

    if (!rayT.surrounds(root)) {
        root = (-b + std::sqrt(d)) / (2 * a);
        if (!rayT.surrounds(root))
            return false;
    }

    rec.t = root;
    rec.point = ray.at(rec.t);

    double len_max = std::sqrt(std::pow(_height / 2, 2) + std::pow(_radius, 2));
    rtx::Vector3D distance = rec.point - center;

    if (distance.length() > len_max) {
        root = (- b + std::sqrt(d)) / (2 * a);
        rec.t = root;
        rec.point = ray.at(rec.t);
        distance = rec.point - center;
        if (distance.length() > len_max)
            return false;
    }

    rtx::Vector3D outwardNormal = rec.point - center;
    rec.setFaceNormal(ray, outwardNormal);
    rec.material = _material;
    if (rec.point.y >= center.y && rec.point.y <= center.y + _height)
        return true;
    return false;
}
