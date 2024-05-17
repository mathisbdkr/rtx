/*
** EPITECH PROJECT, 2024
** Error.hpp
** File description:
** raytracer error class
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

    #include <exception>
    #include <string>

namespace rtx
{
    class Error : public virtual std::exception
    {
    protected:
        std::string _message;

    public:
        virtual const char *what() const noexcept override {return "";}
    };
}

#endif
