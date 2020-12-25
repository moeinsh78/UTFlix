#ifndef FILMSERVICE_H_
#define FILMSERVICE_H_

#include<map>

#include "config.h"
#include "film.h"
#include "error.h"
#include "costumer.h"
#include "database.h"

class FilmService {
public:
    void give_service(std::vector<std::string> command_words, Costumer* logged_costumer);
    void post_films(std::vector<std::string> command_words, Costumer* logged_costumer);
    std::map<std::string, std::string> copy_input_in_map(std::vector<std::string> command_words);
    void send_notification(Costumer* logged_costumer);
    void get_films(std::vector<std::string> command_words, Costumer* logged_costumer);
    void put_films(std::map<std::string, std::string> input, Costumer* logged_costumer);
    void search_films(std::vector<std::string> command_words, Database* database);
    void delete_films(std::vector<std::string> command_words, Costumer* logged_costumer);
};

#endif