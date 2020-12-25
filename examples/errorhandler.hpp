#ifndef _ERROR_HANDLER_
#define _ERROR_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <string> 
#include <ctime>
#include <iostream>

class ErrorHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif