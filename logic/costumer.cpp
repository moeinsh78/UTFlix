#include "costumer.h"

using namespace std;

Costumer::Costumer(string username, string password, string age, string email, bool is_publisher)
{
    Database* database = database->getInstance();
    info[USERNAME] = username;
    info[PASSWORD] = password;
    info[AGE] = age;
    info[EMAIL] = email; 
    publisher = is_publisher;
    id = database->get_next_costumer_id();
    cash = 0;
}

// Costumer::Costumer()
// {
//     info[USERNAME] = ADMIN;
//     info[PASSWORD] = hash_password(ADMIN);
// }

Costumer::~Costumer() {}

// string Costumer::hash_password(string pass) 
// {
//     for (size_t i = 0; i < pass.length(); i++) {
// 		pass[i] = pass[i] + HASH_KEY1;
// 		if (pass[i] % HASH_KEY3 == 0) pass[i] = pass[i] + HASH_KEY2;
// 	}
//     return pass;
// }

void Costumer::add_money(int amount) 
{ 
    cash += amount; 
}

string Costumer::write_info()
{
    string body;
    body += "<p>Username: ";
    body += info[USERNAME];
    body += "</p><p>Email Address: ";
    body += info[EMAIL];
    body += "</p><p>Age: ";
    body += info[AGE];
    body += "</p><p>Cash: ";
    body += to_string(cash);
    body += "</p>";
    return body;
}

string Costumer::purchased_films_table()
{
    Database* database = database->getInstance();
    string body;
    if (purchased_films.size() != 0) {
        body += "<table style=\"width:90%; text-align: center;\">";
        body += "<tr>";
        body += "<th>Name</th>";
        body += "<th>Length</th>";
        body += "<th>Price</th>";
        body += "<th>Rating</th>";
        body += "<th>Production year</th>";
        body += "<th>Directory</th>";
        body += "<th>Summary</th>";
        body += "</tr>";
        for (int i = 0; i < purchased_films.size(); i++) { 
            int film_id = purchased_films[i];
            body += "<tr>";
            body += database->get_film(film_id)->film_detail_row();
            body += "<td>";
            body += "<form action=\"/rate?film_id=";
            body += to_string(film_id);
            body += "\" method=\"post\">";
            body += "<input type=\"number\" min=\"1\" max=\"10\" name=\"rating\">";
            body += "<button type=\"submit\">Rate</button></form>";
            body += "</td>";

            body += "<td>";
            body += "<form action=\"/comment?film_id=";
            body += to_string(film_id);
            body += "\" method=\"post\">";
            body += "<input type=\"textarea\" name=\"comment\">";
            body += "<button type=\"submit\">Submit Comment</button></form>";
            body += "</td>";

            body += "</tr>";
        }
    }
    return body;
}

bool Costumer::add_purchased_film(int film_id, int film_price)
{
    for (int i = 0; i < purchased_films.size(); i++) 
        if (purchased_films[i] == film_id) 
            return false;
    purchased_films.push_back(film_id);
    cash = cash - film_price;
    return true;
}

// bool Costumer::is_bought(int film_id)
// {
//     for (int i = 0; i < purchased_films.size(); i++)
//         if (purchased_films[i] == film_id) return true;
//     return false;
// }
