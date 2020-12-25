#ifndef RATESERVICE_H_
#define RATESERVICE_H_
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

#include "error.h"
#include "config.h"
#include "costumer.h"
#include "film.h"
#include "database.h"

class RateService {
public:
    RateService();
    std::map<std::string, std::string> copy_input_in_map(std::vector<std::string> command_words);
    void post_rate(std::vector<std::string> command_words, Costumer* logged_costumer);
    void send_notification(Costumer* logged_costumer, Film* film);
};

#endif