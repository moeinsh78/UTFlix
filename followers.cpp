#include "followers.h"

using namespace std;

Followers::Followers() {}

void Followers::post_followers(vector<string> command_words, Costumer* logged_costumer) 
{
    if (command_words[2] != QUESTION_MARK) 
        throw BadRequest();
    if (command_words[3] != USER_ID) 
        throw BadRequest();
    int pub_id = stoi(command_words[4]);
    Database* database = database->getInstance();
    Costumer* costumer = database->get_costumer(pub_id);
    if (!costumer->is_publisher()) 
        throw BadRequest();
    logged_costumer->add_following(pub_id);
    costumer->add_follower(logged_costumer->get_id());
    send_notification(logged_costumer, costumer);
    cout << OK << endl;
}

void Followers::get_followers(Costumer* logged_costumer) 
{
    if (!logged_costumer->is_publisher()) 
        throw PermissionDenied();
    Database* database = database->getInstance();
    database->print_followers_info(logged_costumer->get_id());
}

void Followers::send_notification(Costumer* logged_costumer, Costumer* publisher)
{
    Database* database = database->getInstance();
    string notification;
    int publisher_id = publisher->get_id();
    notification = FOLLOW_NOTIF_P1 + logged_costumer->get_username() + ALL_NOTIFS_P2 
                + to_string(logged_costumer->get_id()) + FOLLOW_NOTIF_P3;
    database->send_notif_to_costumer(publisher_id, notification);
}