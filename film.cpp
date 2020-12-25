#include "film.h"

using namespace std;

Film::Film(vector<string> command_words, int pub_id) 
{
    Database* database = database->getInstance();
    for (int i = 3; i < 14; i += 2) {
        if (command_words[i] != NAME && command_words[i] != YEAR
                && command_words[i] != LENGTH && command_words[i] != SUMMARY
                    && command_words[i] != PRICE && command_words[i] != DIRECTOR) 
                        throw BadRequest();
        if (info.count(command_words[i]) != 0) 
            throw BadRequest();
        info.insert(pair<string, string> (command_words[i], command_words[i + 1]));
    }
    if (info.count(NAME) == 0 || info.count(YEAR) == 0 
        || info.count(SUMMARY) == 0 || info.count(LENGTH) == 0 
            ||  info.count(DIRECTOR) == 0 || info.count(PRICE) == 0)
                throw BadRequest();
    publisher_id = pub_id;
    deleted = false;
    id = database->get_next_film_id();
}

Film::~Film()
{
    for (int i = 0; i < comments.size(); i++) 
        delete comments[i];
}

void Film::edit_film_info(map<string, string> input)
{
    if (input.count(NAME) != 0) info[NAME] = input[NAME];
    if (input.count(YEAR) != 0) info[YEAR] = input[YEAR];
    if (input.count(LENGTH) != 0) info[LENGTH] = input[LENGTH];
    if (input.count(SUMMARY) != 0) info[SUMMARY] = input[SUMMARY];
    if (input.count(DIRECTOR) != 0) info[DIRECTOR] = input[DIRECTOR];
    if (input.count(PRICE) != 0) info[PRICE] = input[PRICE];
}

void Film::delete_film()
{
    deleted = true;
}

void Film::print_info()
{
    float grade = calculate_grade();
    cout << id << " | " << info[NAME] << " | " << info[LENGTH] << " | " << info[PRICE] 
         << " | " << grade << " | " << info[YEAR] << " | " << info[DIRECTOR];
}

void Film::print_details() 
{
    cout << "Details of Film " << info[NAME] << endl;
    cout << "Id = " << id << endl;
    cout << "Director = " << info[DIRECTOR] << endl;
    cout << "Length = " << info[LENGTH] << endl;
    cout << "Year = " << info[YEAR] << endl;
    cout << "Summary = " << info[SUMMARY] << endl;
    cout << "Rate = " << calculate_grade() << endl;
    cout << "Price = " << info[PRICE] << endl;
    cout << endl;
    cout << "Comments" << endl;
    for (int i = 0; i < comments.size(); i++) 
        if (!comments[i]->is_deleted()) comments[i]->print_details();
    cout << endl;
}

void Film::print_recommendation() 
{
    cout << id << " | " << info[NAME] << " | " << info[LENGTH] << " | " << info[DIRECTOR];
}

void Film::rate(int costumer_id, int rate)
{
    ratings[costumer_id] = rate;
}

void Film::add_comment(Comment* new_comment)
{
    comments.push_back(new_comment);
}

void Film::delete_comment(int comment_id)
{
    if (comments[comment_id - 1]->is_deleted()) 
        throw NotFound();
    comments[comment_id - 1]->delete_comment();
}

int Film::add_reply(string reply, int comment_id)
{
    if (comment_id > comments.size())   
        throw NotFound();
    if (comments[comment_id - 1]->is_deleted()) 
        throw NotFound();
    comments[comment_id - 1]->add_reply(reply);
    return comments[comment_id - 1]->get_writer_id();
}

float Film::calculate_grade()
{
    if (ratings.size() == 0) return 0.0;
    float sum = 0.0;
    map<int,int>::iterator it;
    for (auto itr = ratings.begin(); itr != ratings.end(); ++itr)
        sum += ratings[itr->first];
    float grade = sum / (float)ratings.size();
    return grade;
}

bool Film::is_acceptable(std::map<std::string, std::string> filters)
{
    bool acceptable = true;
    if (filters.count(NAME) != 0) 
        if (filters[NAME] != info[NAME]) acceptable = false;
    if (filters.count(DIRECTOR) != 0) 
        if (filters[DIRECTOR] != info[DIRECTOR]) acceptable = false;
    if (filters.count(PRICE) != 0) 
        if (filters[PRICE] != info[PRICE]) acceptable = false;
    if (filters.count(MIN_YEAR) != 0) 
        if (filters[MIN_YEAR] > info[YEAR]) acceptable = false;
    if (filters.count(MAX_YEAR) != 0) 
        if (filters[MAX_YEAR] < info[YEAR]) acceptable = false; 
    if (filters.count(MIN_RATE) != 0) 
        if (stoi(filters[MIN_RATE]) > this->calculate_grade()) acceptable = false;
    return acceptable; 
}
