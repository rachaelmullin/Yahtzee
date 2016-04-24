// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// AI.h

#pragma once
#ifndef AI_H
#define AI_H
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

//derived class
class AI
{
	friend class Participants;
	friend class Game;

	public:
		AI();
		string AIroll(int *);
		int choose(int [][3]);
		int score(int [][3], int [][2]);
	private:

};

#endif
