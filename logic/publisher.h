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
    virtual std::string published_films_table(std::string director_filter);
    // virtual std::vector<Film*> get_published_films() { return my_films; }

    Publisher(std::string username, std::string password, std::string age, std::string email, bool is_publisher);
private:
    std::vector<Film*> my_films;
    std::vector<int> followers;
};

#endif