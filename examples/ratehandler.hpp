#ifndef _RATE_HANDLER_
#define _RATE_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class RateHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif
