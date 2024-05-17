/*
** EPITECH PROJECT, 2024
** Sphere.hpp
** File description:
** sphere class
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "Vector3D.hpp"
    #include "Ray.hpp"
    #include "AShape.hpp"
    #include "Interval.hpp"
    #include "IMaterial.hpp"
    #include "ITransformation.hpp"
    #include <memory>

namespace rtx
{
    class Sphere : public virtual rtx::AShape
    {
    private:
        double _radius;
        bool _moving;
        rtx::Vector3D _centerVect;

        static void sphereHitsAngle(const rtx::Point3D& p, double& u, double& v);
        rtx::Point3D getSphereCenter(double time) const {return center + (_centerVect * time);}

    public:
        Sphere();
        Sphere(rtx::Point3D _center, double radius, std::shared_ptr<rtx::IMaterial> material);
        Sphere(rtx::Point3D center1, rtx::Point3D center2, double radius, std::shared_ptr<rtx::IMaterial> material);
        ~Sphere() = default;

        bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const override;

        void setRadius(double radius) {_radius = radius;}
        void setMoving(bool moving) {_moving = moving;}
        void setCenterVect(rtx::Vector3D centerVect) {_centerVect = centerVect;}
    };
}

#endif
