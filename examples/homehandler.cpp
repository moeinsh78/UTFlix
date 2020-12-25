#include "homehandler.hpp"

using namespace std;

Response *HomepageHandler::callback(Request *req) 
{
    Database* database = database->getInstance();
    int id = stoi(req->getSessionId());
    Costumer* costumer = database->get_costumer(id);
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body;
    body += "<!DOCTYPE html>";
    body += "<html>";
    body += "<style> table, th, td { border: 1px solid black; } </style>";
    body += "<body>";
    body += "<h2 style=\"text-align: center;\" >";
    body += costumer->get_username();
    body += "\'s Homepage</h2>";
    body += "<h3>The films you have published:</h3>";
    if (costumer->is_publisher())
        body += costumer->published_films_table(req->getQueryParam("director"));
    body += "<table style=\"width:20%\">";
    body += "<th> Actions </th>";
    body += "<tr> <td>";
    body += "<a href=\"/profile\">My profile</a> <br>";
    if (costumer->is_publisher())
        body += "<a href=\"/upload\">Upload film</a> <br>";
    body += "<a href=\"/details\">Get films details</a> <br>";
    body += "<a href=\"/logout\">Logout</a>";
    body += "</td></tr>";
    body += "</table>";
    body += "<h3>The films you can buy:</h3>";
    body += database->available_films_table(costumer->get_cash(), costumer->get_purchased_films());
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
}
