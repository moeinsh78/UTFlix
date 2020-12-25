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
    ~Comment();
    int get_writer_id() { return writer_id; }
    std::string get_content() { return content; }
private:
    int writer_id;
    int comment_id;
    std::string content;
};

#endif