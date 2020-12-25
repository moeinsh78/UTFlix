#include "database.h"

using namespace std;

Database* Database::instance = NULL;

Database* Database::getInstance()
{
    if (instance == NULL)
        instance = new Database();
    return instance;
}

Database::Database() {}

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
    films.push_back(new_film);
}

bool Database::duplicate_username(std::string new_username)
{
    for (int i = 0; i < costumers.size(); i++) {
        if (new_username == costumers[i]->get_username()) 
            throw BadRequest();
    }
    return false;
}

Costumer* Database::login(std::vector<std::string> command_words) 
{
    string entered_username;
    string entered_pass;
    if (command_words[3] == USERNAME && command_words[5] == PASSWORD) {
        entered_pass = command_words[6];
        entered_username = command_words[4];
    } 
    else if (command_words[5] == USERNAME && command_words[3] == PASSWORD) {
        entered_pass = command_words[4];
        entered_username = command_words[6];
    }
    else throw BadRequest();
    entered_pass = hash_password(entered_pass);
    int user_flag = 0;
    for (int i = 0; i < costumers.size(); i++) {
        if (costumers[i]->get_username() == entered_username) {
            user_flag = 1;
            if (costumers[i]->get_password() == entered_pass)
                return costumers[i];
        }
    }
    if (user_flag == 0) throw NotFound();
    throw BadRequest();
}

string Database::hash_password(string pass) 
{
    for (size_t i = 0; i < pass.length(); i++) {
		pass[i] = pass[i] + HASH_KEY1;
		if (pass[i] % HASH_KEY3 == 0) pass[i] = pass[i] + HASH_KEY2;
	}
    return pass;
}

void Database::set_money(int film_price, int film_grade, int publisher_id)
{
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
}

void Database::set_credit(int publisher_id) 
{ 
    publishers_credit[publisher_id] = 0; 
}

void Database::send_notif_to_costumer(int costumer_id, std::string notification)
{
    costumers[costumer_id - 1]->add_notification(notification);
}

void Database::print_followers_info(int publisher_id)
{
    cout << GET_FOLLOWERS_HEAD1 << endl;
    cout << GET_FOLLOWERS_HEAD2 << endl;
    int counter = 0;
    for (int i = 0; i < costumers.size(); i++) {
        if (costumers[i]->is_following_publisher(publisher_id)) {
            counter++;
            cout << counter << ". ";
            costumers[i]->print_info();
            cout << endl;
        }
    }
}

vector<Film*> Database::search_in_films(map<string, string> filters, vector<int> list_of_films)
{
    vector<Film*> search_result;
    for (int i = 0; i < films.size(); i++)
        if (is_purchased(films[i]->get_id(), list_of_films)) 
            if (films[i]->is_acceptable(filters) && !films[i]->is_deleted()) search_result.push_back(films[i]);
    return search_result;
}

bool Database::is_purchased(int film_id, vector<int> _films)
{
    for (int i = 0; i < _films.size(); i++) 
        if (_films[i] == film_id) return true;
    return false;
}

void Database::recommend_films(Film* film, vector<int> purchased_films)
{
    cout << RECOMMENDATION_HEADER1 << endl;
    cout << RECOMMENDATION_HEADER2 << endl;
    vector<Film*> unpurchased_films;
    vector<float> grades;
    for (int i = 0; i < films.size(); i++) {
        if (films[i]->is_deleted() || films[i] == film) continue;
        bool is_purchased = false;
        for (int j = 0; j < purchased_films.size(); j++)
            if (purchased_films[i] == films[i]->get_id()) is_purchased = true;
        if (!is_purchased) {
            grades.push_back(films[i]->calculate_grade());
            unpurchased_films.push_back(films[i]);
        }
    }
    int num_of_recommendations = 4;
    if (grades.size() < num_of_recommendations) num_of_recommendations = grades.size();
    for (int i = 0; i < num_of_recommendations; i++) {
        cout << i + 1 << ". ";
        float max_grade = grades[0];
        for (int j = 1; j < grades.size(); j++)
            if (grades[j] > max_grade) max_grade = grades[j];
        for (int j = 0; j < unpurchased_films.size(); j++) {
            if (unpurchased_films[j]->calculate_grade() == max_grade) {
                unpurchased_films[j]->print_recommendation();
                unpurchased_films.erase(unpurchased_films.begin() + j);
                grades.erase(grades.begin() + j);
                break;
            }
        }
        cout << endl;
    }
}

std::vector<Film*> Database::search_all_films(std::map<std::string, std::string> filters)
{
    vector<Film*> search_result;
    for (int i = 0; i < films.size(); i++)
        if (films[i]->is_acceptable(filters) && !films[i]->is_deleted()) 
            search_result.push_back(films[i]);
    return search_result;
}