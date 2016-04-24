// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Participants.h

#pragma once
#ifndef _PARTICIPANTS_H_
#define _PARTICIPANTS_H_
#include <iostream>
#include <iomanip>
#include <string>
#include "AI.h"

using namespace std;

//derived class
class Participants
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
		void print();
		int calculateScore(int, int);
		void giveBonus(int);
		void cleanPossible();		
	private:
		string p1;
		string p2;
		int die[5];
		int rollAgain[5];
		int scorecard[14][3];	//variable that translates between all pieces of program
		int mask[14][2];
};

#endif
