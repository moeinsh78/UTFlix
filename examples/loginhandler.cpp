#include "loginhandler.hpp"

using namespace std;

Response *LoginHandler::callback(Request *req) {
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    Database* database = database->getInstance();
    Costumer* logged_costumer;
    Response *res = new Response;
    try {
        logged_costumer = database->login(username, password);
    } catch(exception& e) {
        res = Response::redirect("/error?error_msg=There+is+no+user+with+this+information&url=/");
        return res;
    }
    res = Response::redirect("/home");
    res->setSessionId(to_string(logged_costumer->get_id()));
    // database->print_costumers_info();
    return res;
}
