#include "uploadhandler.hpp"

using namespace std;

Response *UploadHandler::callback(Request *req)
{
    Database* database = database->getInstance();
    Response* res = new Response;
    int publisher_id = stoi(req->getSessionId());
    string name = req->getBodyParam("name");
    string director = req->getBodyParam("director");
    string price = req->getBodyParam("price");
    string summary = req->getBodyParam("summary");
    string production_year = req->getBodyParam("year");
    string length = req->getBodyParam("length");
    Film* new_film = new Film(name, director, price, summary, production_year, length, publisher_id);
    Costumer* costumer = database->get_costumer(publisher_id);
    costumer->add_my_film(new_film);
    database->add_film(new_film);
    res = Response::redirect("/home");
    res->setSessionId(to_string(publisher_id));
    return res;
}
