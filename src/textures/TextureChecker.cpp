/*
** EPITECH PROJECT, 2024
** backup
** File description:
** TextureChecker
*/

#include "TextureChecker.hpp"

rtx::TextureChecker::TextureChecker(double scale, std::shared_ptr<rtx::ITexture> even, std::shared_ptr<rtx::ITexture> odd)
{
    _scale = 1.0 / scale;
    _even = even;
    _odd = odd;
}

rtx::TextureChecker::TextureChecker(double scale, const rtx::Color& c1, const rtx::Color& c2)
{
    _scale = 1.0 / scale;
    _even = std::make_shared<rtx::SolidColor>(c1);
    _odd = std::make_shared<rtx::SolidColor>(c2);
}

rtx::Color rtx::TextureChecker::textureColor(double u, double v, const rtx::Point3D& p) const
{
    int x = int(std::floor(_scale * p.x));
    int y = int(std::floor(_scale * p.y));
    int z = int(std::floor(_scale * p.z));

    bool isEven = (x + y + z) % 2 == 0;
    return isEven ? _even->textureColor(u, v, p) : _odd->textureColor(u, v, p);
}
