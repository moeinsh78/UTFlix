#ifndef LOGIN_H_
#define LOGIN_H_

#include "costumer.h"
#include "database.h"
#include "config.h"
#include "error.h"

class Login {
public:
    Costumer* post_login(std::vector<std::string> command_words);
};

#endif