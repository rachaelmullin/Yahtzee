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
		void roll(int, int); //roll die function
		int checkAce(); //calculates 1's square total
		int checkTwos(); //calculates 2's square total
		int checkThrees(); //calculates 3's square total
		int checkFours(); //calculates 4's square total
		int checkFives(); //calculates 5's square total
		int checkSix(); //calculates 6's square total
		int check3ofKind(); //calculates 3 of a kind square total
		int check4ofKind(); //calculates 4 of a kind square total
		int checkFullHouse(); //calculates full house square total
		int checkSmStraight(); //calculates small straight square total
		int checkLgStraight(); //calculates large straight square total
		int checkYahtzee(); //calculates yahtzee square total
		int checkChance(); //calculates chance square total
		void possiblePoints(int); //calculates possiblePoints for each square given current 5 dice
		void choose(int, int); //player chooses which square to fill
		void print(); //prints scorecard function
		int calculateScore(int, int); //calculates total score
		void giveBonus(int); //if score of upper portion of scorecard qualifies for bonus points
		void cleanPossible(); //clear possible points column
	private:
		string p1; //player 1 name
		string p2; //player 2 name
		int die[5]; //dice array
		int scorecard[14][3];	//scorecard for entire game
		int mask[14][2]; //to know which squares have already been filled by each player
		AI a; //instantiates AI object
};

#endif
