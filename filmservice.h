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
<<<<<<< HEAD
=======
    void give_service(std::vector<std::string> command_words, Costumer* logged_costumer);
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    void post_films(std::vector<std::string> command_words, Costumer* logged_costumer);
    std::map<std::string, std::string> copy_input_in_map(std::vector<std::string> command_words);
    void send_notification(Costumer* logged_costumer);
    void get_films(std::vector<std::string> command_words, Costumer* logged_costumer);
<<<<<<< HEAD
    void put_films(std::vector<std::string> command_words, Costumer* logged_costumer);
=======
    void put_films(std::map<std::string, std::string> input, Costumer* logged_costumer);
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    void search_films(std::vector<std::string> command_words, Database* database);
    void delete_films(std::vector<std::string> command_words, Costumer* logged_costumer);
};

#endif