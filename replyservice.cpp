#include "replyservice.h"

using namespace std;

ReplyService::ReplyService() {}

void ReplyService::post_replies(vector<string> command_words, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
    if (command_words[2] != QUESTION_MARK) 
        throw BadRequest();
    map<string, string> input = copy_input_in_map(command_words);
    if (stoi(input[FILM_ID]) > database->get_films_num())
        throw NotFound();
    Film* film = database->get_film(stoi(input[FILM_ID]));
    if (film->is_deleted())
        throw NotFound();
    if (film->get_publisher_id() != logged_costumer->get_id())
        throw PermissionDenied();    
    int comment_writer_id = film->add_reply(input[CONTENT], stoi(input[COMMENT_ID]));
    send_notification(logged_costumer, comment_writer_id);
    cout << OK << endl;
}

map<string, string> ReplyService::copy_input_in_map(vector<string> command_words)
{
    map<string, string> input;
    if ((command_words.size() % 2) == 0)
        throw BadRequest();
    for (int i = 3; i < command_words.size(); i += 2)
        input.insert(pair<string, string> (command_words[i], command_words[i + 1]));
    if (input.count(FILM_ID) == 0 || input.count(CONTENT) == 0 || input.count(COMMENT_ID) == 0) 
        throw BadRequest();
    return input;
}

void ReplyService::send_notification(Costumer* logged_costumer, int comment_writer_id)
{
    Database* database = database->getInstance();
    string notification;
    notification = REPLY_NOTIF_P1 + logged_costumer->get_username() + ALL_NOTIFS_P2
                + to_string(logged_costumer->get_id()) + REPLY_NOTIF_P3;
    database->send_notif_to_costumer(comment_writer_id, notification);
}