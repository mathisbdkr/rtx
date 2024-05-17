/*
** EPITECH PROJECT, 2024
** backup
** File description:
** TextureChecker
*/

#ifndef TEXTURECHECKER_HPP_
#define TEXTURECHECKER_HPP_

    #include "ITexture.hpp"
    #include "SolidColor.hpp"
    #include "Color.hpp"

namespace rtx
{
    class TextureChecker : public rtx::ITexture {
        public:
            TextureChecker(double scale, std::shared_ptr<rtx::ITexture> even, std::shared_ptr<rtx::ITexture> odd);
            TextureChecker(double scale, const rtx::Color& c1, const rtx::Color& c2);

            rtx::Color textureColor(double u, double v, const rtx::Point3D& p) const override;

        private:
            double _scale;
            std::shared_ptr<rtx::ITexture> _even;
            std::shared_ptr<rtx::ITexture> _odd;
    };
};

#endif /* !TEXTURECHECKER_HPP_ */
