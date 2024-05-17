/*
** EPITECH PROJECT, 2024
** rtx
** File description:
** Cone
*/

#ifndef CONE_HPP_
    #define CONE_HPP_

    #include "Vector3D.hpp"
    #include "Ray.hpp"
    #include "AShape.hpp"
    #include "Interval.hpp"
    #include "IMaterial.hpp"
    #include "ITransformation.hpp"
    #include <memory>

namespace rtx
{
    class Cone : public virtual rtx::AShape
    {
        public:
            Cone();
            Cone(rtx::Point3D center, double radius, double height, std::shared_ptr<IMaterial> material);
            bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const override;

            void setRadius(double radius) {_radius = radius;}
            void setHeight(double height) {_height = height;}

        protected:
        private:
            double _radius;
            double _height;
    };
}

#endif /* !CONE_HPP_ */
