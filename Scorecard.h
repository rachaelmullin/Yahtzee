// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Scorecard.h

#pragma once
#ifndef _SCORECARD_H_
#define _SCORECARD_H_
#include <iostream>
#include <string>
#include "Participants.h"

using namespace std;

//derived class
class Scorecard
{
	friend class Participants;	

	public:
		Scorecard();	//constructor
		void print();	//prints board
		int calculateScore(int, int);
		void giveBonus(int);

	protected:
		int totalScore[2];	//stores total score for both players
		int bonus[2];		//stores whether or not each player has reached th e bonus
		Participants pr;
};

#endif
