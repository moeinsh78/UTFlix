#include "film.h"

using namespace std;

Film::Film(string name, string director, string price, string summary, string p_year, string length, int pub_id)
{
    Database* database = database->getInstance();
    info[NAME] = name;
    info[DIRECTOR] = director;
    info[PRICE] = price;
    info[SUMMARY] = summary; 
    info[YEAR] = p_year; 
    info[LENGTH] = length; 
    pub_id = publisher_id;
    id = database->get_next_film_id();
    deleted = false;
}

Film::~Film()
{
    for (int i = 0; i < comments.size(); i++) 
        delete comments[i];
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

string Film::film_detail_row()
{
    string body;
    body += "<td>";
    body += info[NAME];
    body += "</td><td>";
    body += info[LENGTH];
    body += "</td><td>";
    body += info[PRICE];
    body += "</td><td>";
    body += to_string(calculate_grade());
    body += "</td><td>";
    body += info[YEAR];
    body += "</td><td>";
    body += info[DIRECTOR];
    body += "</td><td>";
    body += info[SUMMARY];
    body += "</td>";
    return body;
}

string Film::write_info()
{
    string body;
    body += "<p>Name: ";
    body += info[NAME];
    body += "</p><p>Length: ";
    body += info[LENGTH];
    body += "</p><p>Price: ";
    body += info[PRICE];
    body += "</p><p>Rating: ";
    body += to_string(calculate_grade());
    body += "</p><p>Production year: ";
    body += info[YEAR];
    body += "</p><p>Director name: ";
    body += info[DIRECTOR];
    body += "</p><p>Sumary: ";
    body += info[SUMMARY];
    body += "</p>";
    return body;
}

string Film::write_recommendation()
{
    string body;
    body += "<td>";
    body += info[NAME];
    body += "</td><td>";
    body += info[LENGTH];
    body += "</td><td>";
    body += info[DIRECTOR];
    body += "</td><td>";
    body += "<form action=\"/details\" method=\"post\"><button type=\"submit\" name=\"film_id\" value=\"";
    body += to_string(id);
    body += "\">Get detail</button></form>";
    body += "</td>";
    return body;
}

void Film::delete_film()
{
    deleted = true;
}

void Film::rate(int costumer_id, int rate)
{
    ratings[costumer_id] = rate;
}

void Film::add_comment(Comment* new_comment)
{
    comments.push_back(new_comment);
}

string Film::comments_info()
{
    string body;
    body += "<h3>Comments</h3>";
    for (int i = 0; i < comments.size(); i++) {
        body += "<p>";
        body += to_string(i + 1);
        body += ". ";
        body += comments[i]->get_content();
        body += "</p>";
    }
    return body;
}
