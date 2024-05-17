/*
** EPITECH PROJECT, 2024
** ConeBuilder.hpp
** File description:
** builder for cones
*/

#ifndef CONEBUILDER_HPP_
    #define CONEBUILDER_HPP_

    #include "IBuilder.hpp"
    #include "IMaterial.hpp"
    #include "Cone.hpp"
    #include "Vector3D.hpp"
    #include <memory>

namespace rtx
{
    class ConeBuilder : public virtual rtx::IBuilder
    {
    private:
        std::unique_ptr<rtx::Cone> _cone;

    public:
        ConeBuilder();
        ~ConeBuilder() = default;

        void reset() override {_cone = std::make_unique<rtx::Cone>();}
        void setPosition(rtx::Point3D position) override {_cone->center = position;}
        void setMaterial(std::shared_ptr<rtx::IMaterial> material) override {_cone->_material = material;}

        void setRadius(double radius) {_cone->setRadius(radius);}
        void setHeight(double height) {_cone->setHeight(height);}
        std::shared_ptr<rtx::Cone> getProduct();
    };
}

#endif
