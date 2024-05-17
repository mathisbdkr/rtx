/*
** EPITECH PROJECT, 2024
** HitRecord.hpp
** File description:
** ray hits
*/

#ifndef HITRECORD_HPP_
    #define HITRECORD_HPP_

namespace rtx
{
    class IMaterial;
}

    #include "Vector3D.hpp"
    #include "Ray.hpp"
    #include "IMaterial.hpp"
    #include <memory>

namespace rtx
{
    class HitRecord
    {
    public:
        rtx::Point3D point;
        rtx::Vector3D normal;
        std::shared_ptr<rtx::IMaterial> material;
        double t;
        double u;
        double v;
        bool frontFace;

        void setFaceNormal(const rtx::Ray &ray, const rtx::Vector3D &outwardNormal);
    };
}

#endif
