#ifndef _CREDIT_HANDLER_
#define _CREDIT_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class CreditHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif
