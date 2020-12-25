#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_
#include <iostream>
#include "manager.h"
#include "config.h"
#include "error.h"
#include <string>


class InputHandler {
public:
    void run_command(std::string command);
    std::vector<std::string> tokenize_command(std::string command);
private:
    Manager manager;
};
#endif