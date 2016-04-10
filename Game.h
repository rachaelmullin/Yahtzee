// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Game.h

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <iomanip>
#include "Scorecard.h"

using namespace std;

//base class
class Game
{
	friend class Participants;
	public:
			Game();
			void choosePlayer(); //decide to play against human or CPU
	protected:
			int scorecard[3][16];	//variable that translates between all pieces of program
			int mask[2][13];
			int computer;
};

#endif
