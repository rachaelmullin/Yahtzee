// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project!
// Game.h

#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <string>
#include <iomanip>
#include "Participants.h"

using namespace std;

//base class
class Game
{
	friend class Participants; //allows Participants class to access Game's private members

	public:
			Game(); //constructor
	private:
			int computer; //decides whether AI will be used 
			Participants p; //instantiates object of class Participants
};

#endif
