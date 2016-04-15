// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Game.cpp

#include <iostream>
#include <string>
#include "Game.h"
#include "Participants.h"
//#include "Scorecard.h"
using namespace std;

Game::Game()
{
	for (int i=0; i<14; i++) {
		p.mask[0][i]=0;
		p.mask[1][i]=0;
	}
	
	int sum, pl;
	int player=1;

	while (sum != 26) {
		sum=0;

		p.print();
		p.roll();
		p.possiblePoints(player);
		p.print();
		p.choose(player);
		
		player=player+1;

		pl=player%2;
		if (pl==0) player=2;
		else player=1;


		for (int i=0; i<14; i++) {
			sum=sum+p.mask[0][i]+p.mask[1][i];
		}

	}	


}	//end of constructor

void Game::choosePlayer()
{
	cout << "Would you like to play against the computer? (Yes = 1, No = 0): " << endl;
	cin >> computer;
}	//end of choosePlayer function
