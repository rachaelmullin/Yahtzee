// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Participants.h

#pragma once
#ifndef _PARTICIPANTS_H_
#define _PARTICIPANTS_H_
#include <iostream>
#include <iomanip>
#include <string>
//#include "Game.h"
//#include "Scorecard.h"

using namespace std;

class Scorecard;

//derived class
class Participants
{
	friend class Game;
	friend class Scorecard;

	public:
		Participants();	//constructor
		void roll();
		int checkAce();
		int checkTwos();
		int checkThrees();
		int checkFours();
		int checkFives();
		int checkSix();
		int check3ofKind();
		int check4ofKind();
		int checkFullHouse();
		int checkSmStraight();
		int checkLgStraight();
		int checkYahtzee();
		int checkChance();
		void possiblePoints(int);
		void choose(int);		
	protected:
		int die[6];
		int rollAgain[6];
		int scorecard[3][16];	//variable that translates between all pieces of program
		int mask[2][13];
		Scorecard sc;
};

#endif
