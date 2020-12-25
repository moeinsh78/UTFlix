#ifndef COMMENTSERVICE_H_
#define COMMENTSERVICE_H_
#include <iostream>
#include <vector>
#include <string>

#include "config.h"
#include "error.h"
#include "costumer.h"
#include "film.h"

class CommentService {
public:
    CommentService();
    void service(std::vector<std::string> command_words, Costumer* logged_costumer);
    void send_notification(Costumer* logged_costumer, Film* film);
<<<<<<< HEAD
    void delete_comments(std::vector<std::string> command_words, Costumer* logged_costumer);
    std::map<std::string, std::string> copy_input_in_map(std::vector<std::string> command_words);
    void post_comments(std::vector<std::string> command_words, Costumer* logged_costumer);
=======
    void delete_comments(std::map<std::string, std::string> input, Costumer* logged_costumer);
    std::map<std::string, std::string> copy_input_in_map(std::vector<std::string> command_words);
    void post_comments(std::map<std::string, std::string> input, Costumer* logged_costumer);
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
};

#endif