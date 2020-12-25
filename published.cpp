#include "published.h"

using namespace std;

Published::Published() {}

void Published::get_published(vector<string> command_words, Costumer* logged_costumer) 
{
    if (command_words[0] != GET) 
        throw NotFound();
    if (!logged_costumer->is_publisher())
        throw PermissionDenied();
    map<string, string> filters = copy_input_in_map(command_words);
    vector<Film*> search_result = search_in_published_films(filters, logged_costumer->get_published_films());
    cout << GET_SEARCH_HEADER << endl;
    for (int i = 0; i < search_result.size(); i++) {
        cout << i + 1 << ". ";
        search_result[i]->print_info();
        cout << endl;
    }
}

map<string, string> Published::copy_input_in_map(vector<string> command_words)
{
    map<string, string> filters;
    for (int i = 3; i < command_words.size(); i += 2) 
        filters.insert(pair<string, string> (command_words[i], command_words[i + 1]));
    return filters;
}

vector<Film*> Published::search_in_published_films(map<string, string> filters, vector<Film*> published_films)
{
    vector<Film*> search_result;
    for (int i = 0; i < published_films.size(); i++)
        if (published_films[i]->is_acceptable(filters)) search_result.push_back(published_films[i]);
    return search_result;
}