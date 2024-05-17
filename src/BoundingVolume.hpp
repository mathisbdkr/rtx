/*
** EPITECH PROJECT, 2024
** BoundingVolume.hpp
** File description:
** bounding volume hierarchy
*/

#ifndef BOUNDINGVOLUME_HPP_
    #define BOUNDINGVOLUME_HPP_

    #include "IShape.hpp"
    #include "AShape.hpp"
    #include "Scene.hpp"
    #include "Interval.hpp"
    #include <memory>
    #include <vector>

namespace rtx
{
    class BoundingVolume : public virtual rtx::AShape
    {
    private:
        std::shared_ptr<rtx::IShape> _left;
        std::shared_ptr<rtx::IShape> _right;

        static bool compareBoxes(const std::shared_ptr<rtx::IShape> a, const std::shared_ptr<rtx::IShape> b, std::size_t axis)
        {
            return a->getBoundingBox()[axis].min < b->getBoundingBox()[axis].min;
        }
        static bool compareBoxesX(const std::shared_ptr<rtx::IShape> a, const std::shared_ptr<rtx::IShape> b)
        {
            return compareBoxes(a, b, 0);
        }
        static bool compareBoxesY(const std::shared_ptr<rtx::IShape> a, const std::shared_ptr<rtx::IShape> b)
        {
            return compareBoxes(a, b, 1);
        }
        static bool compareBoxesZ(const std::shared_ptr<rtx::IShape> a, const std::shared_ptr<rtx::IShape> b)
        {
            return compareBoxes(a, b, 2);
        }

    public:
        BoundingVolume(rtx::Scene scene);
        BoundingVolume(std::vector<std::shared_ptr<rtx::IShape>> &shapes, std::size_t start, std::size_t end);
        ~BoundingVolume() = default;

        bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const override;
    };
}

#endif
