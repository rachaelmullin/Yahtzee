// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Scorecard.h

#ifndef SCORECARD_H
#define SCORECARD_H
#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

//derived class
class Scorecard : public Game
{
	public:
		Scorecard();	//constructor
		void print();	//prints board
		int calculateScore(int, int);
		void giveBonus(int);

	private:
		int totalScore[2];	//stores total score for both players
		int bonus[2];		//stores whether or not each player has reached th e bonus

};

#endif
