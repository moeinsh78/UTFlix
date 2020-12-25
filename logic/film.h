#ifndef FILM_H_
#define FILM_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "config.h"
#include "database.h"
#include "comment.h"

class Film {
public:
    Film(std::string name, std::string director, std::string price, std::string summary, std::string p_year, std::string length, int pub_id);
    ~Film();
    
    void add_comment(Comment* new_comment);
    float calculate_grade();
    std::string write_recommendation();
    std::string write_info();
    std::string film_detail_row();
    std::string comments_info();
    void rate(int costumer_id, int rate);
    int get_next_comment_id() { return comments.size() + 1; }
    int get_id() { return id; }
    int get_price() { return stoi(info[PRICE]); }
    std::string get_director() { return info[DIRECTOR]; }
    int get_publisher_id() { return publisher_id; }
    std::string get_name() { return info[NAME]; }
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