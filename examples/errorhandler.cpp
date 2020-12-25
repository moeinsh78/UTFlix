#include "errorhandler.hpp"

using namespace std;

Response *ErrorHandler::callback(Request *req) 
{
    string error = req->getQueryParam("error_msg");
    string url = req->getQueryParam("url");
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body;
    body += "<!DOCTYPE html>";
    body += "<html>";
    body += "<body style=\"text-align: center;\">";
    body += "<h2>";
    body += error;
    body += "</h2>";
    body += "<h4>";
    body += "<a href=\"";
    body += url;
    body += "\">";
    body += "Return to the previous page</a>";
    body += "</h4>";
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
}