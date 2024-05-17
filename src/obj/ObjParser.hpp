/*
** EPITECH PROJECT, 2024
** ObjParser.hpp
** File description:
** .obj file parser
*/

#ifndef OBJPARSER_HPP_
    #define OBJPARSER_HPP_

    #include "IMaterial.hpp"
    #include "IShape.hpp"
    #include "Vector3D.hpp"
    #include "Error.hpp"
    #include "Scene.hpp"
    #include <vector>
    #include <memory>
    #include <string>
    #include <iomanip>
    #include <tuple>

namespace rtx
{
    class ObjParser
    {
    public:
        class ObjFileError : public virtual rtx::Error
        {
        public:
            ObjFileError(const std::string &msg) noexcept
            {
                _message = msg;
            }

            const char *what() const noexcept override {return _message.c_str();}
        };

    private:
        const std::string _filepath;

        rtx::Point3D getPoint(std::istringstream &iss, const std::string &line, const rtx::Point3D &position) const;
        std::tuple<double, double, double> getFaceIndices(std::istringstream &iss, const std::string &line) const;

    public:
        ObjParser(const std::string &filepath);
        ~ObjParser() = default;

        std::shared_ptr<rtx::IShape> getObject(const rtx::Point3D &position, std::shared_ptr<rtx::IMaterial> material) const;
    };
}

#endif
