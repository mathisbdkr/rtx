/*
** EPITECH PROJECT, 2024
** IBuilder.hpp
** File description:
** builder interface
*/

#ifndef IBUILDER_HPP_
    #define IBUILDER_HPP_

    #include "IMaterial.hpp"
    #include "Vector3D.hpp"
    #include <memory>

namespace rtx
{
    class IBuilder
    {
    public:
        virtual ~IBuilder() = default;

        virtual void reset() = 0;
        virtual void setPosition(rtx::Point3D position) = 0;
        virtual void setMaterial(std::shared_ptr<rtx::IMaterial> material) = 0;
    };
}

#endif
