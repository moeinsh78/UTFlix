#ifndef _DELETE_HANDLER_
#define _DELETE_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class DeleteHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif