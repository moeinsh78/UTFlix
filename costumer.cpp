#include <regex>
#include "costumer.h"

using namespace std;

Costumer::Costumer(vector<string> command_words, bool is_publisher)
{
    Database* database = database->getInstance();
    publisher = is_publisher;
    for (int i = 3; i < 10; i += 2) {
        if (command_words[i] != USERNAME && command_words[i] != PASSWORD
                && command_words[i] != EMAIL && command_words[i] != AGE) 
                    throw BadRequest();
        if (info.count(command_words[i]) != 0) 
            throw BadRequest();
        info.insert(pair<string, string> (command_words[i], command_words[i + 1]));
    }
    if (info.count(PASSWORD) == 0 || info.count(USERNAME) == 0 
        || info.count(AGE) == 0 || info.count(EMAIL) == 0 
            || !is_email_valid(info[EMAIL])) 
        throw BadRequest();
    if (database->duplicate_username(info[USERNAME])) 
        throw BadRequest();
    info[PASSWORD] = hash_password(info[PASSWORD]);
    id = database->get_next_costumer_id();
    cash = 0;
}

Costumer::Costumer()
{
    info[USERNAME] = ADMIN;
    info[PASSWORD] = hash_password(ADMIN);
}

Costumer::~Costumer() {}

string Costumer::hash_password(string pass) 
{
    for (size_t i = 0; i < pass.length(); i++) {
		pass[i] = pass[i] + HASH_KEY1;
		if (pass[i] % HASH_KEY3 == 0) pass[i] = pass[i] + HASH_KEY2;
	}
    return pass;
}

void Costumer::add_following(int publisher_id)
{
    for (int i = 0; i < followings.size(); i++) {
        if (followings[i] == publisher_id) 
            throw BadRequest();
    }
    followings.push_back(publisher_id);
}

void Costumer::add_money(int amount) 
{ 
    cash += amount; 
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

void Costumer::add_credit()
{
    Database* database = database->getInstance();
    cash += database->get_credit(id);
    database->set_credit(id);
}

bool Costumer::is_bought(int film_id)
{
    for (int i = 0; i < purchased_films.size(); i++)
        if (purchased_films[i] == film_id) return true;
    return false;
}

void Costumer::add_notification(string notification)
{
    unread_notifications.push_back(notification);
}

void Costumer::get_unread_notifs() 
{
    cout << GET_NOTIF_HEADER << endl;
    for (int i = unread_notifications.size() - 1; i >= 0 ; i--) 
        cout << unread_notifications.size() - i << ". " << unread_notifications[i] << endl;
    for (int i = 0; i < unread_notifications.size(); i++) {
        notifications.push_back(unread_notifications[i]);
    }
    unread_notifications.clear();
}

void Costumer::get_read_notifs(int limit)
{
    if (limit > notifications.size()) limit = notifications.size();
    int difference = notifications.size() - limit;
    cout << GET_NOTIF_HEADER << endl;
    for (int i = limit - 1; i > -1; i--) 
        cout << notifications.size() - i - difference << ". " << notifications[i + difference] << endl;
}

bool Costumer::is_following_publisher(int publisher_id)
{
    for (int i = 0; i < followings.size(); i++)
        if (followings[i] == publisher_id) return true;
    return false;
}

void Costumer::print_info()
{
    cout << id << " | " << info[USERNAME] << " | " << info[EMAIL];
}

bool Costumer::is_email_valid(const string& email)
{
   const regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return regex_match(email, pattern);
}