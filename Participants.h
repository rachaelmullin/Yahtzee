// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Participants.h

#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Game.h"
#include "Scorecard.h"
using namespace std;

//derived class
class Participants : public Game
{
	friend class Game;
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
	private:
		int die[6];
		int rollAgain[6];
};



#endif
