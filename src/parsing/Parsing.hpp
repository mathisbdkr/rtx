/*
** EPITECH PROJECT, 2024
** rtx
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include <libconfig.h++>
#include <iostream>
#include <vector>
#include <tuple>

namespace rtx
{
    class Parsing {

        private:
        public:
            Parsing();
            ~Parsing();

            struct TransfoInfo {
                std::string transformation;
                double x, y, z;
                double angle;
            };

            struct MaterialInfo {
                std::string material;
                double r, g, b;
                double extra;
                std::vector<TransfoInfo> transfo;
            };

            struct SphereInfo {
                double x, y, z;
                double radius;
                MaterialInfo material;
            };

            struct CylinderConeInfo {
                double x, y, z;
                double height;
                double radius;
                bool isCapped;
                MaterialInfo material;
            };

            struct PlaneTriangleInfo {
                double x, y, z;
                double size_x, size_y, size_z;
                double height_x, height_y, height_z;
                MaterialInfo material;
            };

            struct LightInfo {
                double ambient;
                double diffuse;
                double x, y, z;
                double r, g, b;
                double size;
            };

            struct DirectionalLightInfo {
                double x, y, z;
                double x2, y2, z2;
                double r, g, b;
                double size;
            };

            static double parseCamFOV(libconfig::Config &conf);
            static std::tuple<double, double, double> parseCamPosition(libconfig::Config &conf);
            static int parseCamSample(libconfig::Config &conf);
            static int parseCamDepth(libconfig::Config &conf);
            static std::tuple<double, double, double> parseCamLookAt(libconfig::Config &conf);
            static std::tuple<double, double, double> parseCamAngle(libconfig::Config &conf);
            static float parseCamFocus(libconfig::Config &conf);
            static float parseCamDefocus(libconfig::Config &conf);
            static std::tuple<double, double, double> parseCamColor(libconfig::Config &conf);
            static std::tuple<int, int> parseCamRatio(libconfig::Config &conf);

            static std::vector<SphereInfo> parseSphere(libconfig::Config &conf);

            static std::vector<CylinderConeInfo> parseCylinder(libconfig::Config &conf);
            static std::vector<CylinderConeInfo> parseCone(libconfig::Config &conf);

            static std::vector<PlaneTriangleInfo> parsePlane(libconfig::Config &conf);
            static std::vector<PlaneTriangleInfo> parseTriangles(libconfig::Config &conf);

            static std::pair<double, double> parseAmbientDiffuse(libconfig::Config &conf);
            static std::vector<LightInfo> parsePointLight(libconfig::Config &conf);
            static std::vector<DirectionalLightInfo> parseDirectionalLight(libconfig::Config &conf);
            static std::pair<std::pair<double, double>, std::vector<LightInfo>> parseLights(libconfig::Config &conf);

        protected:

    };
}

#endif /* !PARSING_HPP_ */
