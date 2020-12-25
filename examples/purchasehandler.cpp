#include "purchasehandler.hpp"

using namespace std;

Response *PurchaseHandler::callback(Request *req) 
{
    Database* database = database->getInstance();
    int costumer_id = stoi(req->getSessionId());
    int film_id = stoi(req->getQueryParam("film_id"));
    Film* film = database->get_film(film_id);
    Costumer* costumer = database->get_costumer(costumer_id);
    if(costumer->add_purchased_film(film->get_id(), film->get_price())) {
        cout << "error 1" << endl;
        database->set_money(film->get_price(), film->calculate_grade(), film->get_publisher_id());
        cout << "error 2" << endl;
        database->edit_recommendation_table(film->get_id(), costumer->get_purchased_films());
        cout << "salaam" << endl;
    }
    Response *res = new Response;
    res = Response::redirect("/home");
    res->setSessionId(to_string(costumer->get_id()));
    return res;
}