#ifndef _DETAIL_HANDLER_
#define _DETAIL_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class DetailHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif