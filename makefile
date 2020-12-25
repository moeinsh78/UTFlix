<<<<<<< HEAD
CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template

all: $(BUILD_DIR) myserver.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/database.o: logic/database.cpp logic/database.h logic/film.h logic/costumer.h logic/config.h logic/publisher.h
	$(CC) $(CF) -c logic/database.cpp -o $(BUILD_DIR)/database.o

$(BUILD_DIR)/publisher.o: logic/publisher.cpp logic/publisher.h logic/film.h logic/costumer.h logic/config.h logic/database.h
	$(CC) $(CF) -c logic/publisher.cpp -o $(BUILD_DIR)/publisher.o

$(BUILD_DIR)/costumer.o: logic/costumer.cpp logic/costumer.h logic/film.h logic/database.h logic/config.h logic/publisher.h
	$(CC) $(CF) -c logic/costumer.cpp -o $(BUILD_DIR)/costumer.o

$(BUILD_DIR)/film.o: logic/film.cpp logic/film.h logic/costumer.h logic/database.h logic/config.h logic/comment.h
	$(CC) $(CF) -c logic/film.cpp -o $(BUILD_DIR)/film.o

$(BUILD_DIR)/comment.o: logic/comment.cpp logic/comment.h logic/costumer.h logic/database.h logic/config.h
	$(CC) $(CF) -c logic/comment.cpp -o $(BUILD_DIR)/comment.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/signuphandler.o: examples/signuphandler.cpp examples/signuphandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h logic/costumer.h logic/publisher.h
	$(CC) $(CF) -c examples/signuphandler.cpp -o $(BUILD_DIR)/signuphandler.o

$(BUILD_DIR)/loginhandler.o: examples/loginhandler.cpp examples/loginhandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/loginhandler.cpp -o $(BUILD_DIR)/loginhandler.o

$(BUILD_DIR)/errorhandler.o: examples/errorhandler.cpp examples/errorhandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/errorhandler.cpp -o $(BUILD_DIR)/errorhandler.o

$(BUILD_DIR)/credithandler.o: examples/credithandler.cpp examples/credithandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/credithandler.cpp -o $(BUILD_DIR)/credithandler.o

$(BUILD_DIR)/homehandler.o: examples/homehandler.cpp examples/homehandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/homehandler.cpp -o $(BUILD_DIR)/homehandler.o

$(BUILD_DIR)/logouthandler.o: examples/logouthandler.cpp examples/logouthandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/logouthandler.cpp -o $(BUILD_DIR)/logouthandler.o

$(BUILD_DIR)/uploadhandler.o: examples/uploadhandler.cpp examples/uploadhandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/uploadhandler.cpp -o $(BUILD_DIR)/uploadhandler.o

$(BUILD_DIR)/profilehandler.o: examples/profilehandler.cpp examples/profilehandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/profilehandler.cpp -o $(BUILD_DIR)/profilehandler.o

$(BUILD_DIR)/searchhandler.o: examples/searchhandler.cpp examples/searchhandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/searchhandler.cpp -o $(BUILD_DIR)/searchhandler.o

$(BUILD_DIR)/detailhandler.o: examples/detailhandler.cpp examples/detailhandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/detailhandler.cpp -o $(BUILD_DIR)/detailhandler.o

$(BUILD_DIR)/deletehandler.o: examples/deletehandler.cpp examples/deletehandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/deletehandler.cpp -o $(BUILD_DIR)/deletehandler.o

$(BUILD_DIR)/purchasehandler.o: examples/purchasehandler.cpp examples/purchasehandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/purchasehandler.cpp -o $(BUILD_DIR)/purchasehandler.o

$(BUILD_DIR)/ratehandler.o: examples/ratehandler.cpp examples/ratehandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/ratehandler.cpp -o $(BUILD_DIR)/ratehandler.o

$(BUILD_DIR)/commenthandler.o: examples/commenthandler.cpp examples/commenthandler.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/commenthandler.cpp -o $(BUILD_DIR)/commenthandler.o

$(BUILD_DIR)/my_server.o: examples/my_server.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/my_server.cpp -o $(BUILD_DIR)/my_server.o

$(BUILD_DIR)/main.o: examples/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp logic/database.h
	$(CC) $(CF) -c examples/main.cpp -o $(BUILD_DIR)/main.o

myserver.out: $(BUILD_DIR)/my_server.o $(BUILD_DIR)/main.o $(BUILD_DIR)/signuphandler.o $(BUILD_DIR)/ratehandler.o $(BUILD_DIR)/detailhandler.o $(BUILD_DIR)/commenthandler.o $(BUILD_DIR)/searchhandler.o $(BUILD_DIR)/deletehandler.o $(BUILD_DIR)/uploadhandler.o $(BUILD_DIR)/loginhandler.o $(BUILD_DIR)/profilehandler.o $(BUILD_DIR)/errorhandler.o $(BUILD_DIR)/logouthandler.o $(BUILD_DIR)/homehandler.o $(BUILD_DIR)/purchasehandler.o $(BUILD_DIR)/credithandler.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/database.o $(BUILD_DIR)/costumer.o $(BUILD_DIR)/publisher.o $(BUILD_DIR)/film.o $(BUILD_DIR)/comment.o
	$(CC) $(CF) $(BUILD_DIR)/my_server.o $(BUILD_DIR)/main.o $(BUILD_DIR)/signuphandler.o $(BUILD_DIR)/ratehandler.o $(BUILD_DIR)/detailhandler.o $(BUILD_DIR)/commenthandler.o $(BUILD_DIR)/searchhandler.o $(BUILD_DIR)/deletehandler.o $(BUILD_DIR)/uploadhandler.o $(BUILD_DIR)/loginhandler.o $(BUILD_DIR)/profilehandler.o $(BUILD_DIR)/errorhandler.o $(BUILD_DIR)/logouthandler.o $(BUILD_DIR)/homehandler.o $(BUILD_DIR)/purchasehandler.o $(BUILD_DIR)/response.o $(BUILD_DIR)/credithandler.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/database.o $(BUILD_DIR)/costumer.o $(BUILD_DIR)/publisher.o $(BUILD_DIR)/film.o $(BUILD_DIR)/comment.o -o myserver.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null
=======
CC := g++ -std=c++11
all: a.out

a.out: main.o inputhandler.o database.o manager.o signup.o costumer.o publisher.o login.o film.o filmservice.o money.o followers.o buy.o rateservice.o comment.o commentservice.o replyservice.o notifservice.o purchaseditems.o published.o
	$(CC) -o a.out main.o inputhandler.o database.o manager.o signup.o costumer.o publisher.o login.o film.o filmservice.o money.o followers.o buy.o rateservice.o comment.o commentservice.o replyservice.o notifservice.o purchaseditems.o published.o

main.o: main.cpp inputhandler.h
	$(CC) -c main.cpp -o main.o

inputhandler.o: inputhandler.cpp inputhandler.h config.h error.h manager.h
	$(CC) -c inputhandler.cpp -o inputhandler.o

database.o: database.cpp database.h film.h costumer.h error.h config.h
	$(CC) -c database.cpp -o database.o

manager.o: manager.cpp manager.h error.h costumer.h signup.h filmservice.h money.h followers.h buy.h rateservice.h commentservice.h notifservice.h purchaseditems.h published.h
	$(CC) -c manager.cpp -o manager.o

signup.o: signup.cpp signup.h costumer.h config.h error.h database.h publisher.h login.h
	$(CC) -c signup.cpp -o signup.o

costumer.o: costumer.cpp costumer.h config.h database.h error.h film.h
	$(CC) -c costumer.cpp -o costumer.o

publisher.o: publisher.cpp publisher.h costumer.h film.h
	$(CC) -c publisher.cpp -o publisher.o

login.o: login.cpp login.h costumer.h database.h config.h error.h
	$(CC) -c login.cpp -o login.o

film.o: film.cpp film.h config.h error.h database.h comment.h
	$(CC) -c film.cpp -o film.o

filmservice.o: filmservice.cpp filmservice.h costumer.h film.h config.h error.h database.h
	$(CC) -c filmservice.cpp -o filmservice.o

money.o: money.cpp money.h config.h error.h costumer.h
	$(CC) -c money.cpp -o money.o

followers.o: followers.cpp followers.h config.h error.h costumer.h
	$(CC) -c followers.cpp -o followers.o

buy.o: buy.cpp buy.h config.h error.h costumer.h film.h
	$(CC) -c buy.cpp -o buy.o

rateservice.o: rateservice.cpp rateservice.h config.h error.h costumer.h film.h database.h
	$(CC) -c rateservice.cpp -o rateservice.o

commentservice.o: commentservice.cpp commentservice.h config.h error.h costumer.h film.h
	$(CC) -c commentservice.cpp -o commentservice.o

comment.o: comment.cpp comment.h config.h error.h
	$(CC) -c comment.cpp -o comment.o

replyservice.o: replyservice.cpp replyservice.h config.h error.h costumer.h film.h
	$(CC) -c replyservice.cpp -o replyservice.o

notifservice.o: notifservice.cpp notifservice.h config.h error.h costumer.h
	$(CC) -c notifservice.cpp -o notifservice.o

purchaseditems.o: purchaseditems.cpp purchaseditems.h config.h error.h costumer.h film.h
	$(CC) -c purchaseditems.cpp -o purchaseditems.o

published.o: published.cpp published.h config.h error.h costumer.h film.h
	$(CC) -c published.cpp -o published.o

.PHONY: clean
clean:
	rm *.o
	rm a.out
>>>>>>> 66a94918b4dd259678b6bddc5d7701b119d34103
