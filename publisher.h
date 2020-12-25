#ifndef PUBLISHER_H_
#define PUBLISHER_H_
#include <iostream>
#include "costumer.h"
#include "film.h"
#include <string>
#include <vector>

class Costumer;

class Publisher : public Costumer {
public:
    virtual void add_my_film(Film* my_new_film);
    virtual void add_follower(int costumer_id);
    virtual void send_film_notif_to_followers(std::string notification);
    virtual std::vector<Film*> get_published_films() { return my_films; }

    Publisher(std::vector<std::string> command_words, bool is_publisher);
private:
    std::vector<Film*> my_films;
    std::vector<int> followers;
};

#endif