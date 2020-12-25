#ifndef _SIGNUP_HANDLER_
#define _SIGNUP_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include "../logic/costumer.h"
#include "../logic/publisher.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class SignupHandler : public RequestHandler {
public:
    Response *callback(Request *);
    Costumer* create_account(std::string username, std::string password, std::string age, 
                                                std::string email, bool is_publisher);
};

#endif
