#ifndef _COMMENT_HANDLER_
#define _COMMENT_HANDLER_

#include "../server/server.hpp"
#include "../logic/database.h"
#include <cstdlib> 
#include <ctime>
#include <string>  
#include <iostream>

class CommentHandler : public RequestHandler {
public:
    Response *callback(Request *);
};

#endif
