#include "money.h"

using namespace std;

Money::Money() {}

void Money::give_service(vector<string> command_words, Costumer* logged_costumer)
{
    int amount;
    if (command_words[0] != POST) 
        throw BadRequest();
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
}