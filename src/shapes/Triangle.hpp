/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-raytracer-yanis.harkouk
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
    #define TRIANGLE_HPP_

    #include "Vector3D.hpp"
    #include "Ray.hpp"
    #include "AShape.hpp"
    #include "Interval.hpp"
    #include "IMaterial.hpp"
    #include <memory>

namespace rtx
{
    class Triangle : public virtual rtx::AShape
    {
        public:
            Triangle();
            Triangle(rtx::Point3D p0, rtx::Point3D p1, rtx::Point3D p2, std::shared_ptr<rtx::IMaterial> material);
            bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const override;

            void setPoint0(rtx::Point3D p0) {_p0 = p0;}
            void setPoint1(rtx::Point3D p1) {_p1 = p1;}
            void setPoint2(rtx::Point3D p2) {_p2 = p2;}

            void updateCenter();

        private:
            rtx::Point3D _p0;
            rtx::Point3D _p1;
            rtx::Point3D _p2;
    };
}

#endif /* !TRIANGLE_HPP_ */
