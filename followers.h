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
<<<<<<< HEAD
=======
    void service(std::vector<std::string> command_words, Costumer* logged_costumer);
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    void get_followers(Costumer* logged_costumer);
    void post_followers(std::vector<std::string> command_words, Costumer* logged_costumer); 
    void send_notification(Costumer* logged_costumer, Costumer* publisher);
};

#endif