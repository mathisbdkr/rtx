/*
** EPITECH PROJECT, 2024
** SphereBuilder.hpp
** File description:
** builder for spheres
*/

#ifndef SPHEREBUILDER_HPP_
    #define SPHEREBUILDER_HPP_

    #include "IBuilder.hpp"
    #include "IMaterial.hpp"
    #include "Sphere.hpp"
    #include "Vector3D.hpp"
    #include <memory>

namespace rtx
{
    class SphereBuilder : public virtual rtx::IBuilder
    {
    private:
        std::unique_ptr<rtx::Sphere> _sphere;

    public:
        SphereBuilder();
        ~SphereBuilder() = default;

        void reset() override {_sphere = std::make_unique<rtx::Sphere>();}
        void setPosition(rtx::Point3D position) override {_sphere->center = position;}
        void setMaterial(std::shared_ptr<rtx::IMaterial> material) override {_sphere->_material = material;}

        void setRadius(double radius) {_sphere->setRadius(radius);}
        std::shared_ptr<rtx::Sphere> getProduct();
    };
}

#endif
