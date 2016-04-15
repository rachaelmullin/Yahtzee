// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Game.h

#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <string>
#include <iomanip>
//#include "Scorecard.h"
#include "Participants.h"

using namespace std;

//base class
class Game
{
	friend class Participants;
	//friend class Scorecard;

	public:
			Game();
			void choosePlayer(); //decide to play against human or CPU
			//void print();
	private:
			int computer;
			//Scorecard scr;
			Participants p;
};

#endif
