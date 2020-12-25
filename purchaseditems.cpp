#include "purchaseditems.h"

using namespace std;

PurchasedItems::PurchasedItems() {}

PurchasedItems::~PurchasedItems() {}

void PurchasedItems::get_purchased(vector<string> command_words, Costumer* logged_costumer)
{
    Database* database = database->getInstance();
    if (command_words[0] != GET) 
        throw NotFound();
    map<string, string> filters = copy_input_in_map(command_words);
    vector<Film*> search_result = database->search_in_films(filters,
                                            logged_costumer->get_purchased_films());
    cout << GET_SEARCH_HEADER << endl;
    for (int i = 0; i < search_result.size(); i++) {
        cout << i + 1 << ". ";
        search_result[i]->print_info();
        cout << endl;
    }
}

map<string, string> PurchasedItems::copy_input_in_map(vector<string> command_words)
{
    map<string, string> filters;
    for (int i = 3; i < command_words.size(); i += 2) 
        filters.insert(pair<string, string> (command_words[i], command_words[i + 1]));
    return filters;
}