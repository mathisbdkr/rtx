/*
** EPITECH PROJECT, 2024
** IPC.cpp
** File description:
** Inter Process Communication encapsulation
*/

#include "IPC.hpp"
#include "Camera.hpp"
#include <unistd.h>
#include <iomanip>
#include <sys/wait.h>
#include <iostream>

rtx::IPC::IPC(std::size_t nbProcesses)
    : _nbProcesses(nbProcesses)
    , _pids(_nbProcesses)
    , _pipefds(_nbProcesses)
{}

std::stringstream rtx::IPC::recoverValues(std::size_t buffsize)
{
    std::stringstream out;

    for (std::size_t i = 0; i < _nbProcesses; i++) {
        int status = 0;
        char buffer[buffsize];

        memset(buffer, 0, buffsize);
        while (read(_pipefds[i][0], buffer, buffsize - 1) > 0) {
            out << buffer;
            memset(buffer, 0, buffsize);
        }
        waitpid(_pids[i], &status, 0);
        std::clog << "Process n°" << i << " done.\n";
        close(_pipefds[i][0]);
    }
    return out;
}
