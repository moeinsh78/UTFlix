#ifndef NOTIFSERVICE_H_
#define NOTIFSERVICE_H_
#include <iostream>
#include <vector>
#include <string>

#include "config.h"
#include "error.h"
#include "costumer.h"

class NotifService{
public:
    NotifService();
    void get_service(std::vector<std::string> command_words, Costumer* logged_costumer);
};

#endif