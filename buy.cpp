#include "buy.h"

using namespace std;

Buy::Buy() {}

void Buy::post_buy(vector<string> command_words, Costumer* logged_costumer)
{
    if (command_words[0] != POST) 
        throw NotFound();
    if (command_words[2] != QUESTION_MARK || command_words[3] != FILM_ID)
        throw BadRequest();
    Database* database = database->getInstance();
    if (database->get_films_num() < stoi(command_words[4]))
        throw NotFound();
    Film* purchasing_film = database->get_film(stoi(command_words[4]));
    if (purchasing_film->is_deleted())
        throw NotFound();
    if (logged_costumer->get_cash() < purchasing_film->get_price()) 
        throw PermissionDenied();
    if(logged_costumer->add_purchased_film(purchasing_film->get_id(), purchasing_film->get_price())) {
        database->set_money(purchasing_film->get_price(), 
            purchasing_film->calculate_grade(), purchasing_film->get_publisher_id());
<<<<<<< HEAD
        database->edit_recommendation_table(purchasing_film->get_id(), logged_costumer->get_purchased_films());
        send_notification(logged_costumer, purchasing_film);
    }
    cout << OK << endl;
=======
        send_notification(logged_costumer, purchasing_film);
    }
    cout << OK << endl;
    //cout << logged_costumer->get_cash() << endl;
>>>>>>> 0b9f556f7bce9f6c559e24ee298b821adf9ef437
}

void Buy::send_notification(Costumer* logged_costumer, Film* film)
{
    Database* database = database->getInstance();
    string notification;
    int publisher_id = film->get_publisher_id();
    notification = BUY_NOTIF_P1 + logged_costumer->get_username() 
                + ALL_NOTIFS_P2 + to_string(logged_costumer->get_id()) + BUY_NOTIF_P3 
                + film->get_name() + ALL_NOTIFS_P4 + to_string(film->get_id()) + ".";
    database->send_notif_to_costumer(publisher_id, notification);
}