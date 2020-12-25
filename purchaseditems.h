#ifndef PURCHASEDITEMS_H_
#define PURCHASEDITEMS_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "database.h"
#include "error.h"
#include "costumer.h"
#include "film.h"


class PurchasedItems {
public:
    PurchasedItems();
    ~PurchasedItems();
    void get_purchased(std::vector<std::string> command_words, Costumer* logged_costumer);
    std::map<std::string, std::string> copy_input_in_map(std::vector<std::string> command_words);
};


#endif