#include "filmservice.h"

using namespace std;

<<<<<<< HEAD
=======
void FilmService::give_service(vector<string> command_words, Costumer* logged_costumer)
{
    if (command_words[0] == POST) {
        if (!logged_costumer->is_publisher()) throw PermissionDenied();
        post_films(command_words, logged_costumer);
    }
    else if(command_words[0] == PUT) {
        if (!logged_costumer->is_publisher()) throw PermissionDenied();
        if (command_words[2] != QUESTION_MARK)
            throw BadRequest();
        map<string, string> input = copy_input_in_map(command_words);
        put_films(input, logged_costumer);
    }
    else if(command_words[0] == GET) 
        get_films(command_words, logged_costumer);
    else if(command_words[0] == DELETE) {
        if (!logged_costumer->is_publisher()) throw PermissionDenied();
        delete_films(command_words, logged_costumer);
    }
    else throw BadRequest();
}

>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
map<string, string> FilmService::copy_input_in_map(vector<string> command_words)
{
    map<string, string> input;
    for (int i = 3; i < command_words.size(); i += 2) 
        input.insert(pair<string, string> (command_words[i], command_words[i + 1]));
    return input;
}

void FilmService::post_films(vector<string> command_words, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
<<<<<<< HEAD
    if (!logged_costumer->is_publisher()) 
        throw PermissionDenied();
=======
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    if (command_words[2] != QUESTION_MARK)
        throw BadRequest();
    Film* new_film = new Film(command_words, logged_costumer->get_id());
    logged_costumer->add_my_film(new_film);
    database->add_film(new_film);
    send_notification(logged_costumer);
    cout << OK << endl;
}

<<<<<<< HEAD
void FilmService::put_films(vector<string> command_words, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
    if (command_words[2] != QUESTION_MARK)
        throw BadRequest();
    if (!logged_costumer->is_publisher()) 
        throw PermissionDenied();
    map<string, string> input = copy_input_in_map(command_words);
=======
void FilmService::put_films(map<string, string> input, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    if (input.count(FILM_ID) == 0) 
        throw BadRequest();
    if (stoi(input[FILM_ID]) > database->get_films_num())
        throw NotFound();
    Film* editing_film = database->get_film(stoi(input[FILM_ID]));
    if (editing_film->is_deleted())
        throw NotFound();
    if (logged_costumer->get_id() != editing_film->get_publisher_id())
        throw PermissionDenied();
    editing_film->edit_film_info(input);
    cout << OK << endl;
}

void FilmService::delete_films(vector<string> command_words, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
<<<<<<< HEAD
    if (!logged_costumer->is_publisher()) 
        throw PermissionDenied();
=======
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    if(command_words[3] != FILM_ID)
        throw BadRequest();
    if (stoi(command_words[4]) > database->get_films_num())
        throw NotFound();
    Film* deleting_film = database->get_film(stoi(command_words[4]));
    if (deleting_film->is_deleted())
        throw NotFound();
    if (logged_costumer->get_id() != deleting_film->get_publisher_id())
        throw PermissionDenied();
    deleting_film->delete_film();
    cout << OK << endl;
}

void FilmService::get_films(vector<string> command_words, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
    bool is_search = true;
    int film_id;
    for (int i = 3; i < command_words.size(); i++) {
        if (command_words[i] == FILM_ID) {
            is_search = false;
            film_id = stoi(command_words[i + 1]);
        }
    }
    if (is_search) 
        search_films(command_words, database);
    else {
        if (command_words[2] != QUESTION_MARK) 
            throw BadRequest(); 
        if (stoi(command_words[4]) > database->get_films_num())
            throw NotFound();
        Film* film = database->get_film(film_id);
        if (film->is_deleted())
            throw NotFound();
        film->print_details();
        database->recommend_films(film, logged_costumer->get_purchased_films());
    }
}

void FilmService::send_notification(Costumer* logged_costumer)
{
    string notification;
    notification = FILM_NOTIF_P1 + logged_costumer->get_username() + ALL_NOTIFS_P2 
                + to_string(logged_costumer->get_id()) + FILM_NOTIF_P3;
    logged_costumer->send_film_notif_to_followers(notification);
}

void FilmService::search_films(vector<string> command_words, Database* database) {
    map<string, string> filters = copy_input_in_map(command_words);
    vector<Film*> search_result = database->search_all_films(filters);
    cout << GET_SEARCH_HEADER << endl;
    for (int i = 0; i < search_result.size(); i++) {
        cout << i + 1 << ". ";
        search_result[i]->print_info();
        cout << endl;
    }
}