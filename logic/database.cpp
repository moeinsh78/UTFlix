#include "database.h"

using namespace std;

Database* Database::instance = NULL;

Database::Database() {}

Database* Database::getInstance()
{
    if (instance == NULL)
        instance = new Database();
    return instance;
}

Database::~Database() 
{
    for (int i = 0; i < films.size(); i++) 
        delete films[i];
    for (int i = 0; i < costumers.size(); i++) 
        delete costumers[i];
}

void Database::add_costumer(Costumer* new_costumer)
{
    costumers.push_back(new_costumer);
}

void Database::add_film(Film* new_film)
{
    for (int i = 0; i < recommendation_table.size(); i++) 
        recommendation_table[i].push_back(0);
    vector<int> new_vec;
    films.push_back(new_film);
    for (int i = 0; i < films.size(); i++)
        new_vec.push_back(0);
    recommendation_table.push_back(new_vec);
}

bool Database::duplicate_username(std::string new_username)
{
    for (int i = 0; i < costumers.size(); i++)
        if (new_username == costumers[i]->get_username()) 
            return true;
    
    return false;
}

Costumer* Database::login(string username, string password) 
{
    int user_flag = 0;
    for (int i = 0; i < costumers.size(); i++) {
        if (costumers[i]->get_username() == username) {
            user_flag = 1;
            if (costumers[i]->get_password() == password)
                return costumers[i];
        }
    }
    if (user_flag == 0) throw NotFound();
}

void Database::print_costumers_info()
{
    for (int i = 0; i < costumers.size(); i++) {
        cout << "Id = " << costumers[i]->get_id();
        cout << "Username = " << costumers[i]->get_username();
        cout << "Pass = " << costumers[i]->get_password();
        cout << endl;
    }
}

string Database::available_films_table(int cash, vector<int> purchased_films)
{
    string body;
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
    for (int i = 0; i < films.size(); i++) {
        if (!films[i]->is_deleted() && cash >= films[i]->get_price() && !is_purchased(films[i]->get_id(), purchased_films)) {
            body += "<tr>";
            body += films[i]->film_detail_row();
            body += "<td>";
            body += "<form action=\"/buy?film_id=";
            body += to_string(films[i]->get_id());
            body += "\" method=\"post\"><button type=\"submit\">Buy</button></form>";
            body += "</td>";
            body += "</tr>";
        }
    } 
    body += "</table>";
    return body;
}


void Database::set_money(int film_price, int film_grade, int publisher_id)
{
    // Costumer* publisher = costumers[publisher_id - 1];
    if (film_grade >= GOOD_GRADE) {
        publishers_credit[publisher_id] += ((float)film_price * GOOD_GRADE_PERCENTAGE);
        network_budget += ((float)film_price * (1 - GOOD_GRADE_PERCENTAGE));
    }
    else if (film_grade < BAD_GRADE) {
        publishers_credit[publisher_id] += ((float)film_price * BAD_GRADE_PERCENTAGE);
        network_budget += ((float)film_price * (1 - BAD_GRADE_PERCENTAGE));
    }
    else {
        publishers_credit[publisher_id] += ((float)film_price * AVERAGE_GRADE_PERCENTAGE);
        network_budget += ((float)film_price * (1 - AVERAGE_GRADE_PERCENTAGE));
    }
    //costumers[publisher_id - 1]->add_money(publishers_credit[publisher_id]);
    //publishers_credit[publisher_id] = 0;
}


bool Database::is_purchased(int film_id, vector<int> _films)
{
    for (int i = 0; i < _films.size(); i++) 
        if (_films[i] == film_id) return true;
    return false;
}

string Database::recommend_films(Film* film, vector<int> purchased_films)
{
    string body;
    body += "<h4>Recommend films:</h4>";
    int num_of_recommendations = 4;
    vector<int> weights_copy;
    vector<bool> availability;
    for (int i = 0; i < films.size(); i++) {
        if (films[i]->is_deleted() || is_purchased(films[i]->get_id(), purchased_films) || films[i] == film)
            availability.push_back(false);
        else 
            availability.push_back(true);
    }

    for (int i = 0; i < films.size(); i++) 
        if (availability[i]) 
            weights_copy.push_back(recommendation_table[film->get_id() - 1][i]);
    if (weights_copy.size() < num_of_recommendations) num_of_recommendations = weights_copy.size();
    int size = weights_copy.size();
    int limit = size - num_of_recommendations;
    sort(weights_copy.begin(), weights_copy.end());
    body += "<table style=\"width:50%; text-align: center;\">";
    body += "<tr>";
    body += "<th>Name</th>";
    body += "<th>Length</th>";
    body += "<th>Directory</th>";
    body += "</tr>";
    for (int i = size - 1; i > limit - 1; i--) {
        bool found = false;
        for (int j = 0; j < films.size(); j++) {
            if (weights_copy[i] == recommendation_table[film->get_id() - 1][j] && availability[j] == true) {
                body += "<tr>";
                body += films[j]->write_recommendation();
                availability[j] = false;
                found = true;
                body += "</tr>";
            }
            if (found) j = films.size();
        }
    }
    return body;
}

void Database::edit_recommendation_table(int film_id, vector<int> purchased_films)
{
    for (int i = 0; i < purchased_films.size(); i++) {
        if (purchased_films[i] != film_id) {
            recommendation_table[film_id - 1][purchased_films[i] - 1]++;
            recommendation_table[purchased_films[i] - 1][film_id - 1]++;
        }
    }
}

// std::vector<Film*> Database::search_all_films(std::map<std::string, std::string> filters)
// {
//     vector<Film*> search_result;
//     for (int i = 0; i < films.size(); i++)
//         if (films[i]->is_acceptable(filters) && !films[i]->is_deleted()) 
//             search_result.push_back(films[i]);
//     return search_result;
// }