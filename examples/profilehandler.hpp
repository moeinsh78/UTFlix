#ifndef _PROF_HANDLER_
#define _PROF_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class ProfileHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif
