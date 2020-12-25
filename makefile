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
