#ifndef COSTUMER_H_
#define COSTUMER_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "database.h"
#include "error.h"
#include "config.h"
#include "film.h"

class Film;

class Costumer {
public:
<<<<<<< HEAD
    Costumer();
=======
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    Costumer(std::vector<std::string> command_words, bool is_publisher);
    ~Costumer();

    virtual void add_my_film(Film* my_new_film) {};
    virtual void add_follower(int costumer_id) {};
    virtual void send_film_notif_to_followers(std::string notification) {};
    virtual std::vector<Film*> get_published_films() {};

    std::string hash_password(std::string pass); 
    void print_info();
    bool is_following_publisher(int publisher_id);
    int get_num_of_notifications() { return notifications.size(); }
    std::vector<int> get_purchased_films() { return purchased_films; }
    void get_read_notifs(int limit);
    void get_unread_notifs();
    void add_notification(std::string notification);
    bool add_purchased_film(int film_id, int film_price);
    void add_following(int publisher_id);
    bool is_bought(int film_id);
    void add_credit();
    bool is_email_valid(const std::string& email);
    int get_cash() { return cash; }
    int get_id() { return id; }
    std::string get_username() { return info[USERNAME]; }
    std::string get_password() { return info[PASSWORD]; }
    bool is_publisher() { return publisher; }
    void add_money(int amount);
protected:
    std::vector<std::string> notifications;
    std::vector<std::string> unread_notifications;
    std::vector<int> followings;
    std::vector<int> purchased_films;
    int cash;
    int id;
    std::map<std::string, std::string> info;
    bool publisher;
};
#endif