#ifndef FOLLOWERS_H_
#define FOLLOWERS_H_
#include <iostream>
#include <vector>
#include <string>

#include "config.h"
#include "error.h"
#include "costumer.h"

class Followers {
public:
    Followers();
    void service(std::vector<std::string> command_words, Costumer* logged_costumer);
    void get_followers(Costumer* logged_costumer);
    void post_followers(std::vector<std::string> command_words, Costumer* logged_costumer); 
    void send_notification(Costumer* logged_costumer, Costumer* publisher);
};

#endif