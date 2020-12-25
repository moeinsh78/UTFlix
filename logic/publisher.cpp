#include "publisher.h"

using namespace std;

Publisher::Publisher(string username, string password, string age, string email, bool is_publisher)
    : Costumer(username, password, age, email, is_publisher) {}

void Publisher::add_my_film(Film* my_new_film)
{
    my_films.push_back(my_new_film);
}

string Publisher::published_films_table(string director_filter)
{
    string body;
    body += "<h4>Search for a specific director:</h4>";
    body += "<form action=\"search\" method=\"post\">";
    body += "<input type=\"text\" name=\"director\" placeholder=\"Enter director's name...\" required>";
    body += "<button type=\"submit\">Search</button></form>";
    body += "<table style=\"width:80%; text-align: center;\">";
    body += "<tr>";
    body += "<th>Name</th>";
    body += "<th>Length</th>";
    body += "<th>Price</th>";
    body += "<th>Rating</th>";
    body += "<th>Production year</th>";
    body += "<th>Directory</th>";
    body += "<th>Summary</th>";
    body += "</tr>";
    for (int i = 0; i < my_films.size(); i++) {
        if (!my_films[i]->is_deleted() && (director_filter == "" || director_filter == my_films[i]->get_director())) {
            body += "<tr>";
            body += my_films[i]->film_detail_row();
            body += "<td>";
            body += "<form action=\"/delete?film_id=";
            body += to_string(my_films[i]->get_id());
            body += "\" method=\"post\"><button type=\"submit\">Delete</button></form>";
            body += "</td>";
            body += "</tr>";
        }
    } 
    body += "</table>";
    return body;
}