#ifndef REPLYSERVICE_H_
#define REPLYSERVICE_H_
#include <iostream>
#include <vector>
#include <string>

#include "config.h"
#include "error.h"
#include "costumer.h"
#include "film.h"

class ReplyService {
public:
    ReplyService();
    void post_replies(std::vector<std::string> command_words, Costumer* logged_costumer);
    std::map<std::string, std::string> copy_input_in_map(std::vector<std::string> command_words);
    void send_notification(Costumer* logged_costumer, int comment_writer_id);
};

#endif