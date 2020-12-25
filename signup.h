#ifndef SIGNUP_H_
#define SIGNUP_H_

#include "costumer.h"
#include "publisher.h"
#include "database.h"
#include "config.h"
#include "error.h"

class Signup {
public:
    Costumer* post_signup(std::vector<std::string> command_words);
    bool is_publisher(std::vector<std::string> command_words);
};

#endif