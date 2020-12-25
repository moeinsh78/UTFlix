#include "manager.h"

using namespace std;

Manager::Manager() 
{
    logged_costumer = nullptr;
}

void Manager::make_request(vector<string> command_words)
{
    if (command_words[0] == "") {}
    else if (command_words[1] == SIGNUP) {
        Signup* signup_service = new Signup();
        logged_costumer = signup_service->post_signup(command_words);
        delete signup_service;
    }
    else if (command_words[1] == LOGIN) {
        Login* login_service = new Login();
        logged_costumer = login_service->post_login(command_words);
        delete login_service;
    }
    else if (command_words[1] == FILMS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        FilmService* film_service = new FilmService();
        film_service->give_service(command_words, logged_costumer);
        delete film_service;
    }
    else if (command_words[1] == FOLLOWERS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        Followers* follow_service = new Followers();
        follow_service->service(command_words, logged_costumer);
        delete follow_service;
    }
    else if (command_words[1] == MONEY) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        Money* money_service = new Money();
        money_service->give_service(command_words, logged_costumer);
        delete money_service;
    }
    else if (command_words[1] == BUY) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        Buy* buying_service = new Buy();
        buying_service->post_buy(command_words, logged_costumer);
        delete buying_service;
    }
    else if (command_words[1] == RATE) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        RateService* rate_service = new RateService();
        rate_service->post_rate(command_words, logged_costumer);
        delete rate_service;
    }
    else if (command_words[1] == COMMENTS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        CommentService* cmservice = new CommentService();
        cmservice->service(command_words, logged_costumer);
        delete cmservice;
    }
    else if (command_words[1] == REPLIES) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        ReplyService* repservice = new ReplyService();
        repservice->post_replies(command_words, logged_costumer);
        delete repservice;
    }
    else if (command_words[1] == PUBLISHED) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        Published* published = new Published();
        published->get_published(command_words, logged_costumer);
        delete published;
    }
    else if (command_words[1] == PURCHASED) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        PurchasedItems* purchased = new PurchasedItems();
        purchased->get_purchased(command_words, logged_costumer);
        delete purchased;
    }
    else if (command_words[1] == NOTIFICATIONS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        NotifService* notifservice = new NotifService();
        notifservice->get_service(command_words, logged_costumer);
        delete notifservice;
    }
    else throw NotFound();
}
