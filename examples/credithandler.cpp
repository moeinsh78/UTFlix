#include "credithandler.hpp"

using namespace std;

Response *CreditHandler::callback(Request *req) 
{
    Database* database = database->getInstance();
    Costumer* costumer = database->get_costumer(stoi(req->getSessionId()));
    int added_credit = stoi(req->getBodyParam("amount"));
    costumer->add_money(added_credit);
    Response* res = new Response;
    res = Response::redirect("/home");
    res->setSessionId(to_string(costumer->get_id()));
    return res;
}