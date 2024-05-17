/*
** EPITECH PROJECT, 2024
** ObjParser.cpp
** File description:
** .obj file parser
*/

#include "ObjParser.hpp"
#include "Triangle.hpp"
#include <fstream>

rtx::ObjParser::ObjParser(const std::string &filepath) : _filepath(filepath)
{
}

rtx::Point3D rtx::ObjParser::getPoint(std::istringstream &iss, const std::string &line, const rtx::Point3D &position) const
{
    double x;
    double y;
    double z;

    if (iss >> x >> y >> z)
        return rtx::Point3D(position.x + x, position.y + y, position.z + z);
    throw ObjFileError("parse error at line \"" + line + '\"');
}

std::tuple<double, double, double> rtx::ObjParser::getFaceIndices(std::istringstream &iss, const std::string &line) const
{
    std::vector<int> faceIndices;
    int index;

    while (iss >> index)
        faceIndices.push_back(index - 1);
    if (faceIndices.size() == 3)
        return std::make_tuple(faceIndices[0], faceIndices[1], faceIndices[2]);
    throw ObjFileError("parse error at line \"" + line + "\", expected triangle");
}

std::shared_ptr<rtx::IShape> rtx::ObjParser::getObject(const rtx::Point3D &position, std::shared_ptr<rtx::IMaterial> material) const
{
    std::shared_ptr<rtx::IShape> object = std::make_shared<rtx::Scene>();
    std::vector<rtx::Point3D> pointList;
    std::vector<std::tuple<double, double, double>> indexList;
    std::string line;
    std::ifstream objFile(_filepath);

    if (!objFile.is_open())
        throw ObjFileError("couldn't open file " + _filepath);
    while (std::getline(objFile, line)) {
        if (line.empty() || line[0] == '#')
            continue;
        std::istringstream iss(line);
        std::string token;

        iss >> token;
        if (token == "v")
            pointList.push_back(getPoint(iss, line, position));
        if (token == "f")
            indexList.push_back(getFaceIndices(iss, line));
    }
    objFile.close();
    for (const auto &indices : indexList)
        dynamic_cast<rtx::Scene*>(object.get())->add(std::make_shared<rtx::Triangle>(pointList[std::get<0>(indices)], pointList[std::get<1>(indices)], pointList[std::get<2>(indices)], material));
    return object;
}
