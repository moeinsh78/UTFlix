#include "inputhandler.h"

using namespace std;

void InputHandler::run_command(string command)
{
    vector<string> command_words = tokenize_command(command);
    try {
        if (command_words[0] == GET)
            manager.make_get_requests(command_words);
        else if (command_words[0] == POST){
            manager.make_post_requests(command_words);
        }
        else if (command_words[0] == "") {}
        else 
            manager.other_requests(command_words);
    } catch(exception& e) {
        cout << e.what() << endl;
    }
}

vector<string> InputHandler::tokenize_command(string command)
{
    vector<string> command_words;
    int space_pos = 0;
    while(space_pos != string::npos) {
        command = command.substr(space_pos);
        int pos = 0;
        while(command[pos] == SPACE) pos++;
        space_pos = command.find_first_of(SPACE, pos);
        command_words.push_back(command.substr(pos, space_pos - pos));
    }
    return command_words;
}