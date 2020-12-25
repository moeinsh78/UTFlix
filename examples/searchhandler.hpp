#ifndef _SEARCH_HANDLER_
#define _SEARCH_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class SearchHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif
