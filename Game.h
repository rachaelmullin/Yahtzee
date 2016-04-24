// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
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
			void choosePlayer(); //decide to play against human or CPU
	private:
<<<<<<< HEAD
			int computer;
			Participants p;
=======
			int computer; //decides whether AI will be used 
			Participants p; //instantiates object of class Participants
>>>>>>> b49b002ecd54a6dc2033587cd32939572880109c
};

#endif
