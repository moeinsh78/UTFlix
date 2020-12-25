#include "logouthandler.hpp"

using namespace std;

Response *LogoutHandler::callback(Request *req)
{
    Response* res = new Response;
    res = Response::redirect("/");
    res->setSessionId("");
    return res;
}