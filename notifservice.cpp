#include "notifservice.h"

using namespace std;

NotifService::NotifService() {}

void NotifService::get_service(vector<string> command_words, Costumer* logged_costumer)
{
    if (command_words[0] != GET) 
        throw NotFound();
    if (command_words[2] == READ) {
        int limit = logged_costumer->get_num_of_notifications();
        for (int i = 4; i < command_words.size(); i++) {
            if (command_words[i] == LIMIT) limit = stoi(command_words[i + 1]);
        }
        if (limit < 0) throw BadRequest();
        logged_costumer->get_read_notifs(limit);
    }
    else {
        logged_costumer->get_unread_notifs();
    }
}
