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
<<<<<<< HEAD
    void make_post_requests(std::vector<std::string> command_words);
    void make_get_requests(std::vector<std::string> command_words);
    void other_requests(std::vector<std::string> command_words);
=======
    void make_request(std::vector<std::string> command_words);
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
private:
    Costumer* logged_costumer;
};

#endif