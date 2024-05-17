/*
** EPITECH PROJECT, 2024
** ITexture.hpp
** File description:
** texture interface
*/

#ifndef ITEXTURE_HPP_
    #define ITEXTURE_HPP_

    #include "Ray.hpp"
    #include "HitRecord.hpp"
    #include "Interval.hpp"

namespace rtx
{
    class ITexture {
        public:
            virtual ~ITexture() = default;

            virtual rtx::Color textureColor(double u, double v, const rtx::Point3D& p) const = 0;
    };
};

#endif /* !ITEXTURE_HPP_ */
