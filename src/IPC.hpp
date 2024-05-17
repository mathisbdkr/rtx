/*
** EPITECH PROJECT, 2024
** IPC
** File description:
** Inter Process Communication encapsulation
*/

#ifndef IPC_HPP_
    #define IPC_HPP_

    #include "Error.hpp"
    #include "IShape.hpp"
    #include "Camera.hpp"
    #include <vector>
    #include <unistd.h>
    #include <functional>
    #include <sys/wait.h>
    #include <cstring>
    #include <cerrno>
    #include <iomanip>
    #include <thread>

namespace rtx
{
    class IPC {
        public:
            class PipeFailure : public virtual rtx::Error {
                public:
                    PipeFailure(std::string why) noexcept
                    {
                        _message = std::string("pipe: ") + why;
                    }

                     const char *what() const noexcept override {return _message.c_str();}
            };

            class ForkFailure : public virtual rtx::Error {
                public:
                    ForkFailure(std::string why) noexcept
                    {
                        _message = std::string("fork: ") + why;
                    }

                    const char *what() const noexcept override {return _message.c_str();}
            };

    private:
        std::size_t _nbProcesses;
        std::vector<int[2]> _pipefds;
        std::vector<pid_t> _pids;

    public:
        IPC(std::size_t nbProcesses = std::thread::hardware_concurrency());
        ~IPC() = default;

        template<class T>
        void launch(void (T::*func)(std::stringstream&, std::size_t, std::size_t, const rtx::IShape&), T &obj, const rtx::IShape &shape, std::size_t imageHeight)
            {
                std::size_t range = imageHeight / _nbProcesses;

                for (std::size_t i = 0; i < _nbProcesses; i++) {
                    if (pipe(_pipefds[i]) == -1)
                        throw rtx::IPC::PipeFailure(std::strerror(errno));
                    pid_t pid = fork();

                    if (pid < 0)
                        throw rtx::IPC::ForkFailure(std::strerror(errno));
                    else if (pid == 0) {
                        close(_pipefds[i][0]);
                        std::stringstream val;
                        std::size_t start = i * range;
                        std::size_t end = (i + 1 >= _nbProcesses) ? imageHeight : (i + 1) * range;
                        (obj.*func)(val, start, end, shape);
                        write(_pipefds[i][1], val.str().c_str(), val.str().length());
                        exit(0);
                    } else {
                        close(_pipefds[i][1]);
                        _pids[i] = pid;
                    }
                }
            }

        std::stringstream recoverValues(std::size_t buffsize);
    };
}

#endif
