#ifndef MONEY_H_
#define MONEY_H_
#include <iostream>
#include <vector>
#include <string>

#include "config.h"
#include "error.h"
#include "costumer.h"


class Money {
public:
    Money();
    void give_service(std::vector<std::string> command_words, Costumer* logged_costumer);

};

#endif