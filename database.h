#ifndef DATABASE_H_
#define DATABASE_H_
#include <map>
<<<<<<< HEAD
#include <algorithm>
=======
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
#include "costumer.h"
#include "film.h"
#include "error.h"
#include "config.h"

class Film;
class Costumer;

class Database {
public:
    static Database* getInstance();
    ~Database();

    Costumer* login(std::vector<std::string> command_words);
    std::vector<Film*> search_in_films(std::map<std::string, std::string> filters, 
                                                            std::vector<int> list_of_films);
    std::vector<Film*> search_all_films(std::map<std::string, std::string> filters); 
    bool is_purchased(int film_id, std::vector<int> purchased_films);
<<<<<<< HEAD
    void edit_recommendation_table(int film_id, std::vector<int> purchased_films);
=======
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    void recommend_films(Film* film, std::vector<int> purchased_films);
    void print_followers_info(int publisher_id);
    void send_notif_to_costumer(int costumer_id, std::string notification);
    void set_money(int film_price, int film_grade, int publisher_id);
    float get_credit(int publisher_id) { return publishers_credit[publisher_id]; }
    void set_credit(int publisher_id);
    bool duplicate_username(std::string new_username);
    void add_film(Film* new_film);
    void add_costumer(Costumer* new_costumer);
    Film* get_film(int film_id) { return films[film_id - 1]; }
    std::string hash_password(std::string pass); 
    Costumer* get_costumer(int costumer_id) { return costumers[costumer_id - 1]; }
    int get_films_num() { return films.size(); }
    int get_next_film_id () { return films.size() + 1; }
    int get_next_costumer_id () { return costumers.size() + 1; }
<<<<<<< HEAD
    float get_network_budget() { return network_budget; }
=======
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
private:
    static Database* instance;
    Database();

<<<<<<< HEAD
    Costumer* admin;
    float network_budget;
    std::vector< std::vector<int> > recommendation_table;
=======
    float network_budget;
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
    std::map<int, float> publishers_credit;
    std::vector<Film*> films;
    std::vector<Costumer*> costumers;
};


#endif