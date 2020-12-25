#include "rateservice.h"

using namespace std;

RateService::RateService() {}

void RateService::post_rate(vector<string> command_words, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
    if (command_words[0] != POST) 
        throw NotFound();
    map<string, string> input = copy_input_in_map(command_words);
    if (input.count(FILM_ID) == 0 || input.count(SCORE) == 0 || command_words[2] != QUESTION_MARK) 
        throw BadRequest();
    if (stoi(input[SCORE]) < 1 || stoi(input[SCORE]) > 10 || stoi(input[FILM_ID]) > database->get_films_num()) 
        throw BadRequest();
    Film* film = database->get_film(stoi(input[FILM_ID]));
    if (!logged_costumer->is_bought(stoi(input[FILM_ID]))) 
        throw PermissionDenied();
    film->rate(logged_costumer->get_id(), stoi(input[SCORE]));
    send_notification(logged_costumer, film);
    cout << OK << endl;
}

map<string, string> RateService::copy_input_in_map(vector<string> command_words)
{
    map<string, string> input;
    for (int i = 3; i < command_words.size(); i += 2) {
        input.insert(pair<string, string> (command_words[i], command_words[i + 1]));
    }
    for (int i = 0; i < input[SCORE].length(); i++) 
        if (!isdigit(input[SCORE][i])) throw BadRequest();
    return input;
}

void RateService::send_notification(Costumer* logged_costumer, Film* film)
{
    Database* database = database->getInstance();
    string notification;
    int publisher_id = film->get_publisher_id();
    notification = RATE_NOTIF_P1 + logged_costumer->get_username() 
                + ALL_NOTIFS_P2 + to_string(logged_costumer->get_id()) + RATE_NOTIF_P3 
                + film->get_name() + ALL_NOTIFS_P4 + to_string(film->get_id()) + ".";
    database->send_notif_to_costumer(publisher_id, notification);
}