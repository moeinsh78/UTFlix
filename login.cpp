#include "login.h"

using namespace std;

Costumer* Login::post_login(vector<string> command_words)
{
    Database* database = database->getInstance();
    if (command_words[0] != POST) 
        throw NotFound();
    if (command_words[2] != QUESTION_MARK)
        throw BadRequest();
    Costumer* logged_costumer = database->login(command_words);
    cout << OK << endl;
    return logged_costumer;
}
