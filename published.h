#ifndef PUBLISHED_H_
#define PUBLSIHED_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "error.h"
#include "config.h"
#include "film.h"
#include "costumer.h"

class Published {
public:
    Published();
    void get_published(std::vector<std::string> command_words, Costumer* logged_costumer);
    std::map<std::string, std::string> copy_input_in_map(std::vector<std::string> command_words);
    std::vector<Film*> search_in_published_films(std::map<std::string, std::string> filters, std::vector<Film*> published_films);

};

#endif