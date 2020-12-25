#include "money.h"

using namespace std;

Money::Money() {}

<<<<<<< HEAD
void Money::post_money(vector<string> command_words, Costumer* logged_costumer)
{
    int amount;
=======
void Money::give_service(vector<string> command_words, Costumer* logged_costumer)
{
    int amount;
    if (command_words[0] != POST) 
        throw BadRequest();
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    if (command_words[2] == QUESTION_MARK) {
        if (command_words[3] != AMOUNT) throw BadRequest();
        amount = stoi(command_words[4]);
        logged_costumer->add_money(amount);
        //cout << logged_costumer->get_cash() << endl;
        cout << OK << endl;
    }
    else {
        if (!logged_costumer->is_publisher())
            throw PermissionDenied();
        logged_costumer->add_credit();
        cout << OK << endl;
    }
<<<<<<< HEAD
}

void Money::get_money(Costumer* logged_costumer)
{
    Database* database = database->getInstance();
    if (logged_costumer->get_username() == ADMIN)
        cout << database->get_network_budget() << endl;
    else 
        cout << logged_costumer->get_cash() << endl;
    /*int amount;
    if (command_words[2] == QUESTION_MARK) {
        if (command_words[3] != AMOUNT) throw BadRequest();
        amount = stoi(command_words[4]);
        logged_costumer->add_money(amount);
        //cout << logged_costumer->get_cash() << endl;
        cout << OK << endl;
    }
    else {
        if (!logged_costumer->is_publisher())
            throw PermissionDenied();
        logged_costumer->add_credit();
        cout << OK << endl;
    }*/
=======
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
}