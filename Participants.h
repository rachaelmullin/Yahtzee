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
		
	private:
		int die[6];
		int rollAgain[6];
};

#endif
