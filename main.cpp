/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main
*/

#include <memory>
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include "Color.hpp"
#include "Vector3D.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "memes.hpp"
#include "macros.hpp"
#include "Factory.hpp"
#include "Parsing.hpp"

static void displayUsage()
{
    static const std::string memes[NB_MEMES] = {SHRUG_MEME, FORGOT_BRAIN_MEME, SPONGEBOB_MEME, DOOT_DOOT_MEME, RICK_ROLL_MEME, DERP_MEME, NERD_MEME, RTX_ON_MEME};
    std::size_t randValue = randomValue(0, NB_MEMES);

    std::cout << memes[randValue];
    std::cout << "\033[1mUSAGE\033[m:\t./raytracer [-g]\n"
              << "\t\033[1m-g\033[m\tdisplays in real time the pixels drawing (slows the process)\n";
}

static rtx::Scene getScene(libconfig::Config &conf)
{
    rtx::Scene world;
    rtx::Factory factory(conf);

    factory.createWorldFromConfFile(world);
    return world;
}

static rtx::Camera getCam(libconfig::Config &conf)
{
    std::tuple<int, int> ratio = rtx::Parsing::parseCamRatio(conf);
    rtx::Camera cam(std::get<0>(ratio), std::get<1>(ratio));
    std::tuple<double, double, double> color = rtx::Parsing::parseCamColor(conf);
    std::tuple<double, double, double> pos = rtx::Parsing::parseCamPosition(conf);
    std::tuple<double, double, double> lookAt = rtx::Parsing::parseCamLookAt(conf);
    std::tuple<double, double, double> angle = rtx::Parsing::parseCamAngle(conf);
    std::pair<double, double> light = rtx::Parsing::parseAmbientDiffuse(conf);

    cam.backgroundColor = rtx::Color(std::get<0>(color), std::get<1>(color), std::get<2>(color));
    cam.samplesPerPixel = rtx::Parsing::parseCamSample(conf);
    cam.maxDepth = rtx::Parsing::parseCamDepth(conf);
    cam.fov = rtx::Parsing::parseCamFOV(conf);
    cam.cameraPosition = rtx::Point3D(std::get<0>(pos),std::get<1>(pos),std::get<2>(pos));
    cam.lookAt = rtx::Point3D(std::get<0>(lookAt),std::get<1>(lookAt),std::get<2>(lookAt));
    cam.cameraAngle = rtx::Vector3D(std::get<0>(angle),std::get<1>(angle),std::get<2>(angle));
    cam.defocusAngle = rtx::Parsing::parseCamDefocus(conf);
    cam.focusDist = rtx::Parsing::parseCamFocus(conf);
    cam.ambientLight = light.first;
    return cam;
}

static int launch(int ac, const char *av[])
{
    libconfig::Config conf;

    try {
        conf.readFile(av[ac - 1]);
    } catch (const libconfig::FileIOException &) {
        std::cerr << "Could not open the file" << std::endl;
        return 84;
    } catch(const libconfig::ParseException &err) {
        std::cerr << "Parse error at " << err.getFile() << ":" << err.getLine()
            << " - " << err.getError() << std::endl;
        return 84;
    }

    rtx::Scene scene = getScene(conf);
    rtx::Camera cam = getCam(conf);

    try {
        if (ac == 3 && std::string(av[1]) == "-g") {
        cam.renderGraphical(scene, av[2]);
        } else {
            cam.render(scene, av[1]);
        }
    } catch(const rtx::Camera::InvalidFileExtension &err) {
        std::cerr << err.what() << std::endl;
        return 84;
    }
    return 0;
}

int main(int ac, const char *av[])
{
    srand(time(NULL));

    if (ac == 2 && std::string(av[1]) == "--help") {
        displayUsage();
        return 0;
    } else if (ac != 2 && !(ac == 3 && std::string(av[1]) == "-g")) {
        displayUsage();
        return 84;
    }
    return launch(ac, av);
}
