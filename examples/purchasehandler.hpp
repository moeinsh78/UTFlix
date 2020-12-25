#ifndef _PURCHASE_HANDLER_
#define _PURCHASE_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class PurchaseHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif
