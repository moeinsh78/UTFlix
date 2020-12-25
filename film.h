#ifndef FILM_H_
#define FILM_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "config.h"
#include "error.h"
#include "database.h"
#include "comment.h"

class Film {
public:
    Film(std::vector<std::string> command_words, int pub_id);
    ~Film();
    
    bool is_acceptable(std::map<std::string, std::string> filters);
    void add_comment(Comment* new_comment);
    int add_reply(std::string comment, int comment_id);
    void delete_comment(int comment_id);
    void print_recommendation();
    void print_details();
    void print_info();
    float calculate_grade();
    void rate(int costumer_id, int rate);
    int get_next_comment_id() { return comments.size() + 1; }
    int get_id() { return id; }
    int get_price() { return stoi(info[PRICE]); }
    int get_publisher_id() { return publisher_id; }
    std::string get_name() { return info[NAME]; }
    void edit_film_info(std::map<std::string, std::string> input);
    void delete_film();
    bool is_deleted() { return deleted; }
private:
    int id;
    int publisher_id;
    std::vector<Comment*> comments;
    std::map<std::string, std::string> info;
    std::map<int, int> ratings;
    bool deleted;
};
#endif