// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Game.h

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//base class
class Game
{
	public:
			Game();
			void choosePlayer();	//decide to play against human or CPU
	protected:
			int scorecard[2][16];	//variable that translates between all pieces of program
			int computer;
};

#endif
