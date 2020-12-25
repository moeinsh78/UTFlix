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
    void delete_comments(std::vector<std::string> command_words, Costumer* logged_costumer);
    std::map<std::string, std::string> copy_input_in_map(std::vector<std::string> command_words);
    void post_comments(std::vector<std::string> command_words, Costumer* logged_costumer);
};

#endif