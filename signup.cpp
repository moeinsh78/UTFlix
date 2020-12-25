#include <iostream>
#include "signup.h"

using namespace std;

Costumer* Signup::post_signup(vector<string> command_words)
{
    Database* database = database->getInstance();
    if (command_words[0] != POST) 
        throw NotFound();
    if (command_words[2] != QUESTION_MARK)
        throw BadRequest();
    Costumer* new_costumer;
    bool publisher = is_publisher(command_words);
    if(publisher) 
        new_costumer = new Publisher(command_words, publisher);
    else
        new_costumer = new Costumer(command_words, publisher);
    database->add_costumer(new_costumer);
    cout << OK << endl;
    return new_costumer;
}

bool Signup::is_publisher(vector<string> command_words)
{
    bool publisher = false;
    for (int i = 3; i < command_words.size(); i += 2) {
        if (command_words[i] == PUBLISHER) {
            if (command_words[i + 1] == TRUE_P) 
                publisher = true;
            else if (command_words[i + 1] != FALSE_P) 
                throw BadRequest();
        }
    }
    return publisher;
}