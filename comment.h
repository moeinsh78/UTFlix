#ifndef COMMENT_H_
#define COMMENT_H_
#include <iostream>
#include <vector>
#include <string>

#include "config.h"
#include "error.h"

class Comment {
public:
    Comment(std::string content, int id, int costumer_id);
    int get_writer_id() { return writer_id; }
    bool is_deleted() { return deleted; }
    void delete_comment();
    void add_reply(std::string reply);
    void print_details();
private:
    int writer_id;
    int comment_id;
    std::vector<std::string> replies;
    std::string content;
    bool deleted;
};

#endif