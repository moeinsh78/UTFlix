#include "manager.h"

using namespace std;

Manager::Manager() 
{
    logged_costumer = nullptr;
}

<<<<<<< HEAD
void Manager::make_post_requests(vector<string> command_words) 
{
    if (command_words[1] == LOGOUT) {
        if (logged_costumer == nullptr) throw BadRequest();
        logged_costumer = nullptr;
        cout << OK << endl;
    }
    else if (command_words[1] == SIGNUP) {
        if (logged_costumer != nullptr) throw BadRequest();
=======
void Manager::make_request(vector<string> command_words)
{
    if (command_words[0] == "") {}
    else if (command_words[1] == SIGNUP) {
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
        Signup* signup_service = new Signup();
        logged_costumer = signup_service->post_signup(command_words);
        delete signup_service;
    }
    else if (command_words[1] == LOGIN) {
<<<<<<< HEAD
        if (logged_costumer != nullptr) throw BadRequest();
=======
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
        Login* login_service = new Login();
        logged_costumer = login_service->post_login(command_words);
        delete login_service;
    }
<<<<<<< HEAD
=======
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
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
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
<<<<<<< HEAD
    else if (command_words[1] == COMMENTS || command_words[1] == DELETE_COMMENTS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        CommentService* cmservice = new CommentService();
        if (command_words[1] == COMMENTS) 
            cmservice->post_comments(command_words, logged_costumer);
        if (command_words[1] == DELETE_COMMENTS) 
            cmservice->delete_comments(command_words, logged_costumer);
=======
    else if (command_words[1] == COMMENTS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        CommentService* cmservice = new CommentService();
        cmservice->service(command_words, logged_costumer);
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
        delete cmservice;
    }
    else if (command_words[1] == REPLIES) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        ReplyService* repservice = new ReplyService();
        repservice->post_replies(command_words, logged_costumer);
        delete repservice;
    }
<<<<<<< HEAD
    else if (command_words[1] == FILMS || command_words[1] == DELETE_FILMS || command_words[1] == PUT_FILMS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        FilmService* film_service = new FilmService();
        if (command_words[1] == FILMS)
            film_service->post_films(command_words, logged_costumer);
        if (command_words[1] == PUT_FILMS)
            film_service->put_films(command_words, logged_costumer);
        if (command_words[1] == DELETE_FILMS)
            film_service->delete_films(command_words, logged_costumer);
        delete film_service;
    }
    else if (command_words[1] == FOLLOWERS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        Followers* follow_service = new Followers();
        follow_service->post_followers(command_words, logged_costumer);
        delete follow_service;
    }
    else if (command_words[1] == MONEY) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        Money* money_service = new Money();
        money_service->post_money(command_words, logged_costumer);
        delete money_service;
    }
    else 
        throw NotFound();
}

void Manager::make_get_requests(vector<string> command_words)
{
    if (logged_costumer == nullptr) throw PermissionDenied();
    if (command_words[1] == PUBLISHED) {
=======
    else if (command_words[1] == PUBLISHED) {
        if (logged_costumer == nullptr) throw PermissionDenied();
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
        Published* published = new Published();
        published->get_published(command_words, logged_costumer);
        delete published;
    }
    else if (command_words[1] == PURCHASED) {
<<<<<<< HEAD
=======
        if (logged_costumer == nullptr) throw PermissionDenied();
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
        PurchasedItems* purchased = new PurchasedItems();
        purchased->get_purchased(command_words, logged_costumer);
        delete purchased;
    }
    else if (command_words[1] == NOTIFICATIONS) {
<<<<<<< HEAD
=======
        if (logged_costumer == nullptr) throw PermissionDenied();
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
        NotifService* notifservice = new NotifService();
        notifservice->get_service(command_words, logged_costumer);
        delete notifservice;
    }
<<<<<<< HEAD
    else if (command_words[1] == FILMS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        FilmService* film_service = new FilmService();
        film_service->get_films(command_words, logged_costumer);
        delete film_service;
    }
    else if (command_words[1] == FOLLOWERS) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        Followers* follow_service = new Followers();
        follow_service->get_followers(logged_costumer);
        delete follow_service;
    }
    else if (command_words[1] == MONEY) {
        if (logged_costumer == nullptr) throw PermissionDenied();
        Money* money_service = new Money();
        money_service->get_money(logged_costumer);
        delete money_service;
    }
    else 
        throw NotFound();
}

void Manager::other_requests(vector<string> command_words)
{
    throw BadRequest();
=======
    else throw NotFound();
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
}
