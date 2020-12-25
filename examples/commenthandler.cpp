#include "commenthandler.hpp"

using namespace std;

Response *CommentHandler::callback(Request *req) 
{
    Database* database = database->getInstance();
    int film_id = stoi(req->getQueryParam("film_id"));
    string comment = req->getBodyParam("comment");
    Costumer* costumer = database->get_costumer(stoi(req->getSessionId()));
    Film* film = database->get_film(film_id);
    Comment* new_comment = new Comment(comment, film->get_next_comment_id(), costumer->get_id());
    film->add_comment(new_comment);
    Response *res = new Response;
    res = Response::redirect("/profile");
    res->setSessionId(to_string(costumer->get_id()));
    return res;
}
