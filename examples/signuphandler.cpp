#include "signuphandler.hpp"

using namespace std;

Response *SignupHandler::callback(Request *req)
{
    Database* database = database->getInstance();
    Response* res = new Response();
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    string repeat_password = req->getBodyParam("repeat_password");
    if (repeat_password != password) {
        res = Response::redirect("/error?error_msg=You+didnt+repeat+your+password+correctly&url=/signup");
        return res;
    }    
    string age = req->getBodyParam("age");
    string email = req->getBodyParam("email");  
    string is_pub = req->getBodyParam("publisher");
    bool is_publisher = false;
    if (is_pub == "publisher") is_publisher = true;
    if (database->duplicate_username(username)) {
        res = Response::redirect("/error?error_msg=This+username+already+exists&url=/signup");
        return res;
    }
    Costumer* new_costumer = create_account(username, password, age, email, is_publisher);
    res = Response::redirect("/home");
    res->setSessionId(to_string(new_costumer->get_id()));
    return res;
}

Costumer* SignupHandler::create_account(string username, string password, string age, string email, bool is_publisher) 
{
    Database* database = database->getInstance();
    Costumer* new_costumer;
    if(is_publisher) 
        new_costumer = new Publisher(username, password, age, email, is_publisher);
    else
        new_costumer = new Costumer(username, password, age, email, is_publisher);
    database->add_costumer(new_costumer); 
    return new_costumer;
    database->print_costumers_info();
}