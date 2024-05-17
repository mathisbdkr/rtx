/*
** EPITECH PROJECT, 2024
** rtx
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <iostream>
#include <memory>
#include <libconfig.h++>
#include <map>
#include "IMaterial.hpp"
#include "Metal.hpp"
#include "Matte.hpp"
#include "Dielectric.hpp"
#include "IShape.hpp"
#include "Scene.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "Triangle.hpp"
#include "Error.hpp"
#include "Light.hpp"
#include "Parsing.hpp"

namespace rtx {
    class Factory {
        private:
            libconfig::Config &_conf;

            std::shared_ptr<rtx::IShape> applyTransformations(std::vector<rtx::Parsing::TransfoInfo> &transfoInfos, std::shared_ptr<rtx::IShape> shape) const;

        public:
            Factory(libconfig::Config &conf);
            ~Factory() = default;

            template<typename Shape, typename... Argument>
            static std::shared_ptr<rtx::IShape> createShape(Argument... args) {
                return std::make_shared<Shape>(std::forward<Argument>(args)...);
            }
            template<typename Material, typename ...Argument>
            static std::shared_ptr<rtx::IMaterial> createMaterial(Argument... args) {
                return std::make_shared<Material>(std::forward<Argument>(args)...);
            }
            template<typename Transfo, typename ...Argument>
            static std::shared_ptr<rtx::ITransformation> createTransformation(Argument... args) {
                return std::make_shared<Transfo>(std::forward<Argument>(args)...);
            }

            void createWorldFromConfFile(rtx::Scene &world) const noexcept;
            void createSphereFromConfFile(rtx::Scene &world) const noexcept;
            void createPlaneFromConfFile(rtx::Scene &world) const noexcept;
            void createTriangleFromConfFile(rtx::Scene &world) const noexcept;
            void createConeFromConfFile(rtx::Scene &world) const noexcept;
            void createCylinderFromConfFile(rtx::Scene &world) const noexcept;
            void createLightFromConfFile(rtx::Scene &world) const noexcept;
            void createDirectionalLightFromConfFile(rtx::Scene &world) const noexcept;
    };
}

#endif /* !FACTORY_HPP_ */
