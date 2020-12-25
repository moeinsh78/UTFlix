#ifndef _LOGIN_HANDLER_
#define _LOGIN_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include "../logic/error.h"
#include <cstdlib> 
#include <string> 
#include <ctime>
#include <iostream>

class LoginHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif
