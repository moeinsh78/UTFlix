#include "deletehandler.hpp"

using namespace std;

Response *DeleteHandler::callback(Request *req) 
{
    Database* database = database->getInstance();
    Costumer* costumer = database->get_costumer(stoi(req->getSessionId()));
    Response *res = new Response;
    Film* film = database->get_film(stoi(req->getQueryParam("film_id")));
    film->delete_film();
    res = Response::redirect("/home");
    res->setSessionId(to_string(costumer->get_id()));
    return res;
}
