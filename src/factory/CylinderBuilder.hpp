/*
** EPITECH PROJECT, 2024
** CylinderBuilder.hpp
** File description:
** builder for cylinders
*/

#ifndef CYLINDERBUILDER_HPP_
    #define CYLINDERBUILDER_HPP_

    #include "IBuilder.hpp"
    #include "IMaterial.hpp"
    #include "Cylinder.hpp"
    #include "Vector3D.hpp"
    #include <memory>

namespace rtx
{
    class CylinderBuilder : public virtual rtx::IBuilder
    {
    private:
        std::unique_ptr<rtx::Cylinder> _cylinder;

    public:
        CylinderBuilder();
        ~CylinderBuilder() = default;

        void reset() override {_cylinder = std::make_unique<rtx::Cylinder>();}
        void setPosition(rtx::Point3D position) override {_cylinder->center = position;}
        void setMaterial(std::shared_ptr<rtx::IMaterial> material) override {_cylinder->_material = material;}

        void setRadius(double radius) {_cylinder->setRadius(radius);}
        void setHeight(double height) {_cylinder->setHeight(height);}
        void setIsCapped(bool isCapped) {_cylinder->setIsCapped(isCapped);}
        std::shared_ptr<rtx::Cylinder> getProduct();
    };
}

#endif
