#include "searchhandler.hpp"

using namespace std;

Response *SearchHandler::callback(Request *req) 
{
    string director = req->getBodyParam("director");
    Response* res = new Response;
    string redirection = "/home?director=";
    redirection += director;
    res = Response::redirect(redirection);
    res->setSessionId(req->getSessionId());
    return res;
}