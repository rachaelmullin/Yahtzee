// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Participants.h

#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Game.h"
using namespace std;

//derived class
class Participants : public Game
{
	public:
		Participants();	//constructor
		void roll();
		int checkAce(int,int);
		int checkTwos(int, int);
		int checkThrees(int, int);
		int checkFours(int, int);
		int checkFives(int, int);
		int checkSix(int, int);
		int check3ofKind(int, int);
		int check4ofKind(int, int);
		int checkFullHouse(int, int);
		int checkSmStraight(int, int);
		int checkLgStraight(int, int);
		int checkYahtzee(int, int);
		int checkChance(int, int);
		
	private:
		int die[6];
		int rollAgain[6];
};



#endif
