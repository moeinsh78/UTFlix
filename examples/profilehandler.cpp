#include "profilehandler.hpp"

using namespace std;

Response *ProfileHandler::callback(Request *req) 
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
    body += "\'s Profile</h2>";
    body += "<table style=\"width:20%\">";
    body += "<th>Information</th>";
    body += "<tr><td>";
    body += costumer->write_info();
    body += "</td></tr>";
    body += "</table>";
    body += costumer->purchased_films_table();
    body += "<p>Add credit to your account:</p>";
    body += "<form action=\"/money\" method=\"post\">";
    body += "<p>Money amount: <input type=\"number\" name=\"amount\" min=\"0\" required>";
    body += "<button type=\"submit\">Add</button></p></form>";
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
