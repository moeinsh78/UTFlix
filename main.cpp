#include <iostream>
#include "inputhandler.h"

using namespace std;

int main()
{
    Database* database = database->getInstance();
    InputHandler input_handler;
    string command;
    while (getline(cin, command))
        input_handler.run_command(command);
    delete database;
    return 0;
}
