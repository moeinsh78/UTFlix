#include "detailhandler.hpp"

using namespace std;

Response *DetailHandler::callback(Request *req) 
{
    Database* database = database->getInstance();
    Response *res = new Response;
    Costumer* costumer = database->get_costumer(stoi(req->getSessionId()));
    int film_id = stoi(req->getBodyParam("film_id"));
    Film* film = database->get_film(film_id);
    cout << "Price: " << film->get_price() << endl;
    res->setHeader("Content-Type", "text/html");
    string body;
    body += "<!DOCTYPE html> <html>";
    body += "<style> table, th, td { border: 1px solid black; } </style>";
    body += "<body>";
    body += film->write_info();
    body += film->comments_info();
    body += "<form action=\"/buy?film_id=";
    body += to_string(film->get_id());
    body += "\" method=\"post\"><button type=\"submit\">Buy this film</button></form>";
    body += "<br>";
    body += database->recommend_films(film, costumer->get_purchased_films());
    body += "<table style=\"width:20%\">";
    body += "<th>Actions</th>";
    body += "<tr><td>";
    body += "<a href=\"/home\">Back to homepage</a> <br>";
    body += "<a href=\"/logout\">Logout</a>";
    body += "</td></tr>";
    body += "</table>";
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
}