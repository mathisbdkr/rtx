/*
** EPITECH PROJECT, 2024
** TriangleBuilder.hpp
** File description:
** builder for triangles
*/

#ifndef TRIANGLEBUILDER_HPP_
    #define TRIANGLEBUILDER_HPP_

    #include "IBuilder.hpp"
    #include "IMaterial.hpp"
    #include "Triangle.hpp"
    #include "Vector3D.hpp"
    #include <memory>

namespace rtx
{
    class TriangleBuilder : public virtual rtx::IBuilder
    {
    private:
        std::unique_ptr<rtx::Triangle> _triangle;

    public:
        TriangleBuilder();
        ~TriangleBuilder() = default;

        void reset() override {_triangle = std::make_unique<rtx::Triangle>();}
        void setPosition(rtx::Point3D) override {_triangle->updateCenter();}
        void setMaterial(std::shared_ptr<rtx::IMaterial> material) override {_triangle->_material = material;}

        void setPoint0(rtx::Point3D p0) {_triangle->setPoint0(p0);}
        void setPoint1(rtx::Point3D p1) {_triangle->setPoint1(p1);}
        void setPoint2(rtx::Point3D p2) {_triangle->setPoint2(p2);}
        std::shared_ptr<rtx::Triangle> getProduct();
    };
}

#endif
