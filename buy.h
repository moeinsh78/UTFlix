#ifndef BUY_H_
#define BUY_H_
#include <iostream>
#include <vector>
#include <string>

#include "error.h"
#include "config.h"
#include "costumer.h"
#include "film.h"

class Buy {
public:
    Buy();
    void post_buy(std::vector<std::string> command_words, Costumer* logged_costumer);
    void send_notification(Costumer* logged_costumer, Film* film);
};
#endif