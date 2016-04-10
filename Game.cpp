// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Game.cpp

#include <iostream>
#include <string>
#include "Game.h"
#include "Participants.h"
#include "Scorecard.h"
using namespace std;

Game::Game()
{
	for (int i=0; i<14; i++) {
		mask[0][i]=0;
		mask[1][i]=0;
	}
	
	int sum, pl;
	int player=1;

	while (sum!=26) {
		sum=0;

		print();
		roll();
		possiblePoints(player);
		print();
		choose(player);
		
		player=player+1;
		pl=player%2;
		if (pl==0) player=2;
		else player=1;


		for (int i=0; i<14; i++) {
			sum=sum+mask[0][i]+mask[1][i];
		}

	}	


}	//end of constructor

void Game::choosePlayer()
{
	cout << "Would you like to play against the computer? (Yes = 1, No = 0): " << endl;
	cin >> computer;
}	//end of choosePlayer function
