/*
** EPITECH PROJECT, 2024
** PlaneBuilder.hpp
** File description:
** builder for planes
*/

#ifndef PLANEBUILDER_HPP_
    #define PLANEBUILDER_HPP_

    #include "IBuilder.hpp"
    #include "IMaterial.hpp"
    #include "Plane.hpp"
    #include "Vector3D.hpp"
    #include <memory>

namespace rtx
{
    class PlaneBuilder : public virtual rtx::IBuilder
    {
    private:
        std::unique_ptr<rtx::Plane> _plane;

    public:
        PlaneBuilder();
        ~PlaneBuilder() = default;

        void reset() override {_plane = std::make_unique<rtx::Plane>();}
        void setPosition(rtx::Point3D position) override {_plane->setPosition(position);}
        void setMaterial(std::shared_ptr<rtx::IMaterial> material) override {_plane->_material = material;}

        void setWidth(rtx::Vector3D width) {_plane->setVectorX(width);}
        void setHeight(rtx::Vector3D height) {_plane->setVectorY(height);}
        std::shared_ptr<rtx::Plane> getProduct();
    };
}

#endif
