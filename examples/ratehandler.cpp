#include "ratehandler.hpp"

using namespace std;

Response *RateHandler::callback(Request *req) 
{
    Database* database = database->getInstance();
    int film_id = stoi(req->getQueryParam("film_id"));
    int rate = stoi(req->getBodyParam("rating"));
    Costumer* costumer = database->get_costumer(stoi(req->getSessionId()));
    Film* film = database->get_film(film_id);
    film->rate(costumer->get_id(), rate);
    Response *res = new Response;
    res = Response::redirect("/profile");
    res->setSessionId(to_string(costumer->get_id()));
    return res;
}