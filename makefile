all:	Yahtzee 

Yahtzee: main.o Game.o Participants.o
	g++ main.o Game.o Participants.o -o Yahtzee

main.o: main.cpp Game.cpp
	g++ -c main.cpp Game.cpp

Game.o: Game.cpp Participants.cpp
	g++ -c Game.cpp Participants.cpp

Participants.o: Participants.cpp
	g++ -c Participants.cpp

clean:
	rm -f *.o Yahtzee
