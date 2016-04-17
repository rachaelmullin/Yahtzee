// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Game.cpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "Game.h"
#include "Participants.h"
//#include "Scorecard.h"
using namespace std;

Game::Game()
{

	cout << "Who is Player 1? (max 10 characters): " << endl;
	cin >> p.p1;
	cout << "Who is Player 2? (max 10 characters): " << endl;
	cin >> p.p2;

	//initialize the scorecard array
	for (int i = 0; i < 14; i ++)
	{
		for (int j = 0; j < 3; j ++)
		{
			p.scorecard[i][j] = 0;
		}	//end for
	}	//end for

	//initialize the mask array
	for (int i=0; i<14; i++) {
		p.mask[i][0]=0;
		p.mask[i][1]=0;
	}
	
	//declare variables
	int sum, pl;
	int player=1;

	while (sum != 26) {
		
		cout << endl << endl << endl << endl;
		if (player == 1)
			cout << "It is " << p.p1 << "'s turn!" << endl;
		else
			cout << "It is " << p.p2 << "'s turn!" << endl;
		sum=0;	//reset sum variable

		p.print();
		p.roll();
		p.possiblePoints(player);
		p.print();
		p.choose(player);
		player=player+1;

		for (int i = 0; i < 5; i ++)
		{
			p.die[i] = 0;
		}

		pl=player%2;
		if (pl==0) player=2;
		else player=1;


		for (int i=0; i<14; i++) {
			sum=sum+p.mask[i][0]+p.mask[i][1];
		}

	}	


}	//end of constructor

void Game::choosePlayer()
{
	cout << "Would you like to play against the computer? (Yes = 1, No = 0): " << endl;
	cin >> computer;
}	//end of choosePlayer function
