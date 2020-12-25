#include "commentservice.h"

using namespace std;

CommentService::CommentService() {}

<<<<<<< HEAD
=======
void CommentService::service(vector<string> command_words, Costumer* logged_costumer)
{
    if (command_words[2] != QUESTION_MARK) 
        throw BadRequest();
    if (command_words[0] == DELETE) {
        if (!logged_costumer->is_publisher()) throw PermissionDenied();
        map<string, string> input = copy_input_in_map(command_words);
        delete_comments(input, logged_costumer);
    }
    else if (command_words[0] == POST) {
        map<string, string> input = copy_input_in_map(command_words);
        post_comments(input, logged_costumer);
        Database* database = database->getInstance();
        if (input.count(FILM_ID) == 0) 
            throw BadRequest();
        Film* editing_film = database->get_film(stoi(input[FILM_ID]));
        if (stoi(input[FILM_ID]) > database->get_films_num() || editing_film->is_deleted())
            throw NotFound();
    }
}

>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
map<string, string> CommentService::copy_input_in_map(vector<string> command_words)
{
    map<string, string> input;
    if ((command_words.size() % 2) == 0)
        throw BadRequest();
    for (int i = 3; i < command_words.size(); i += 2) {
        input.insert(pair<string, string> (command_words[i], command_words[i + 1]));
    }
    return input;
}

<<<<<<< HEAD
void CommentService::post_comments(vector<string> command_words, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
    map<string, string> input = copy_input_in_map(command_words);
    if (stoi(input[FILM_ID]) > database->get_films_num())
        throw NotFound();
    Film* film = database->get_film(stoi(input[FILM_ID]));
    if (command_words[2] != QUESTION_MARK || input.count(FILM_ID) == 0 || input.count(CONTENT) == 0) 
        throw BadRequest();
=======
void CommentService::post_comments(map<string, string> input, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
    if (input.count(FILM_ID) == 0 || input.count(CONTENT) == 0) 
        throw BadRequest();
    if (stoi(input[FILM_ID]) > database->get_films_num())
        throw NotFound();
    Film* film = database->get_film(stoi(input[FILM_ID]));
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    if (film->is_deleted())
        throw NotFound();
    if (!logged_costumer->is_bought(stoi(input[FILM_ID]))) 
        throw PermissionDenied();
    Comment* new_comment = new Comment(input[CONTENT], film->get_next_comment_id(), logged_costumer->get_id());
    film->add_comment(new_comment);
    send_notification(logged_costumer, film);
    cout << OK << endl;
}

<<<<<<< HEAD
void CommentService::delete_comments(vector<string> command_words, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
    map<string, string> input = copy_input_in_map(command_words);
    if (!logged_costumer->is_publisher()) 
        throw PermissionDenied();
=======
void CommentService::delete_comments(map<string, string> input, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    if (input.count(FILM_ID) == 0 || input.count(COMMENT_ID) == 0) 
        throw BadRequest();
    if (stoi(input[FILM_ID]) > database->get_films_num())
        throw NotFound();
    Film* film = database->get_film(stoi(input[FILM_ID]));
    if (film->is_deleted())
        throw NotFound();
    if (logged_costumer->get_id() != film->get_publisher_id())
        throw PermissionDenied();
    film->delete_comment(stoi(input[COMMENT_ID]));
    cout << OK << endl;
}

void CommentService::send_notification(Costumer* logged_costumer, Film* film)
{
    Database* database = database->getInstance();
    string notification;
    int publisher_id = film->get_publisher_id();
    notification = COMMENT_NOTIF_P1 + logged_costumer->get_username() 
                + ALL_NOTIFS_P2 + to_string(logged_costumer->get_id()) + COMMENT_NOTIF_P3 
                + film->get_name() + ALL_NOTIFS_P4 + to_string(film->get_id()) + ".";
    database->send_notif_to_costumer(publisher_id, notification);
}