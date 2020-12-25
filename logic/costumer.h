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
    Costumer(std::string username, std::string password, std::string age, std::string email, bool is_publisher);
    ~Costumer();

    virtual void add_my_film(Film* my_new_film) {};
    virtual std::string published_films_table(std::string director_filter) {};
    // virtual std::vector<Film*> get_published_films() {};

    bool is_following_publisher(int publisher_id);
    std::vector<int> get_purchased_films() { return purchased_films; }
    bool add_purchased_film(int film_id, int film_price);
    void add_following(int publisher_id);
    bool is_bought(int film_id);
    void add_credit();
    int get_cash() { return cash; }
    int get_id() { return id; }
    std::string purchased_films_table();
    std::string write_info();
    std::string get_username() { return info[USERNAME]; }
    std::string get_password() { return info[PASSWORD]; }
    bool is_publisher() { return publisher; }
    void add_money(int amount);
protected:
    std::vector<int> purchased_films;
    int cash;
    int id;
    std::map<std::string, std::string> info;
    bool publisher;
};
#endif