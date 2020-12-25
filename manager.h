#ifndef MANAGER_H_
#define MANAGER_H_
#include <vector>

#include "costumer.h"
#include "signup.h"
#include "error.h"
#include "login.h"
#include "filmservice.h"
#include "money.h"
#include "followers.h"
#include "buy.h"
#include "published.h"
#include "rateservice.h"
#include "commentservice.h"
#include "replyservice.h"
#include "notifservice.h"
#include "purchaseditems.h"

class Manager {
public:
    Manager();
    void make_post_requests(std::vector<std::string> command_words);
    void make_get_requests(std::vector<std::string> command_words);
    void other_requests(std::vector<std::string> command_words);
private:
    Costumer* logged_costumer;
};

#endif