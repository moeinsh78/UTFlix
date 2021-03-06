#ifndef _UPLOAD_HANDLER_
#define _UPLOAD_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include "../logic/costumer.h"
#include "../logic/publisher.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class UploadHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif