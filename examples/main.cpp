#include "loginhandler.hpp"
#include "signuphandler.hpp"
#include "errorhandler.hpp"
#include "uploadhandler.hpp"
#include "homehandler.hpp"
#include "credithandler.hpp"
#include "profilehandler.hpp"
#include "logouthandler.hpp"
#include "detailhandler.hpp"
#include "deletehandler.hpp"
#include "purchasehandler.hpp"
#include "searchhandler.hpp"
#include "ratehandler.hpp"
#include "commenthandler.hpp"
#include "my_server.hpp"
#include "../logic/database.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    Database* database = database->getInstance();
    srand(time(NULL));
    try {
        MyServer server(argc > 1 ? atoi(argv[1]) : 5000);
        server.setNotFoundErrPage("static/404.html");
        server.get("/signup", new ShowPage("static/signup.html"));
        server.get("/logout", new LogoutHandler());
        server.post("/signup", new SignupHandler());
        server.post("/login", new LoginHandler());
        server.post("/upload", new UploadHandler());
        server.get("/details", new ShowPage("static/details.html"));
        server.post("/money", new CreditHandler());
        server.get("/home", new HomepageHandler());
        server.post("/details", new DetailHandler());
        server.post("/delete", new DeleteHandler());
        server.post("/buy", new PurchaseHandler());
        server.post("/rate", new RateHandler());
        server.post("/comment", new CommentHandler());
        server.post("/search", new SearchHandler());
        server.get("/profile", new ProfileHandler());
        server.get("/upload", new ShowPage("static/upload.html"));
        server.get("/error", new ErrorHandler());
        // server.get("/bg.png", new ShowImage("static/bg.jpg"));
        server.get("/", new ShowPage("static/login.html"));
        server.run();
    } catch (Server::Exception e) {
        cerr << e.getMessage() << endl;
    }
    delete database;
}
