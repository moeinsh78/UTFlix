#include "publisher.h"

using namespace std;

Publisher::Publisher(vector<string> command_words, bool is_publisher)
    : Costumer(command_words, is_publisher) {}

void Publisher::add_my_film(Film* my_new_film)
{
    my_films.push_back(my_new_film);
}

void Publisher::add_follower(int costumer_id) 
{
    followers.push_back(costumer_id);
}

void Publisher::send_film_notif_to_followers(std::string notification)
{
    Database* database = database->getInstance();    
    for (int i = 0; i < followers.size(); i++) 
        database->send_notif_to_costumer(followers[i], notification);
}