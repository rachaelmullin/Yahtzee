all:	Yahtzee 

Yahtzee: main.o Game.o Participants.o AI.o
	g++ main.o Game.o Participants.o AI.o -o Yahtzee

main.o: main.cpp Game.cpp
	g++ -c main.cpp Game.cpp

Game.o: Game.cpp Participants.cpp
	g++ -c Game.cpp Participants.cpp

Participants.o: Participants.cpp AI.cpp
	g++ -c Participants.cpp AI.cpp

AI.o: AI.cpp
	g++ -c AI.cpp

clean:
	rm -f *.o Yahtzee
