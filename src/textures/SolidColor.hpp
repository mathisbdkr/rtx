/*
** EPITECH PROJECT, 2024
** backup
** File description:
** SolidColor
*/

#ifndef SOLIDCOLOR_HPP_
    #define SOLIDCOLOR_HPP_

    #include "ITexture.hpp"
    #include "Color.hpp"

namespace rtx
{
    class SolidColor : public rtx::ITexture {
        public:
            SolidColor(const rtx::Color& albedo);
            SolidColor(double r, double g, double b);

            rtx::Color textureColor(double u, double v, const rtx::Point3D& point) const override;
        private:
            rtx::Color _albedo;
    };
};

#endif /* !SOLIDCOLOR_HPP_ */
