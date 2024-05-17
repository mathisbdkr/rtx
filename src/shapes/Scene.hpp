/*
** EPITECH PROJECT, 2024
** Scene.hpp
** File description:
** List of shapes
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include "IShape.hpp"
    #include "AShape.hpp"
    #include "Interval.hpp"
    #include <memory>
    #include <vector>

namespace rtx
{
    class Scene : public virtual rtx::AShape
    {
    public:
        Scene();
        Scene(std::shared_ptr<rtx::IShape> shape);
        ~Scene() = default;

        std::vector<std::shared_ptr<rtx::IShape>> shapes;

        void clear() {shapes.clear();}
        void add(std::shared_ptr<rtx::IShape> shape);
        void add(rtx::Scene &scene);

        bool hits(const rtx::Ray &ray, rtx::Interval rayT, rtx::HitRecord &rec) const override;
    };
}

#endif
