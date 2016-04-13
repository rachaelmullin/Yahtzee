all:	Yahtzee

Yahtzee: main.o Game.o Scorecard.o Participants.o
	g++ main.o Game.o Scorecard.o Participants.o -o Yahtzee

main.o: main.cpp Game.cpp
	g++ -c main.cpp Game.cpp

Game.o: Game.cpp Scorecard.cpp Participants.cpp
	g++ -c Game.cpp Scorecard.cpp Participants.cpp

Scorecard.o: Scorecard.cpp Participants.cpp
	g++ -c Scorecard.cpp Participants.cpp

Participants.o: Participants.cpp
	g++ -c Participants.cpp

clean:
	rm -f *.o Yahtzee
