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
<<<<<<< HEAD
    void post_money(std::vector<std::string> command_words, Costumer* logged_costumer);
    void get_money(Costumer* logged_costumer);
=======
    void give_service(std::vector<std::string> command_words, Costumer* logged_costumer);

>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
};

#endif