// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Game.cpp

#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

Game::Game()
{



}	//end of constructor

void Game::choosePlayer()
{
	cout << "Would you like to play against the computer? (Yes = 1, No = 0): " << endl;
	cin >> computer;
}	//end of choosePlayer function
