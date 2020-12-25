#ifndef _HOME_HANDLER_
#define _HOME_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class HomepageHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif
