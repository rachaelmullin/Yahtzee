// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Game.cpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "Game.h"
#include "Participants.h"
using namespace std;

Game::Game()
{
cout << endl << endl;
cout << "  /$$     /$$ /$$$$$$  /$$   /$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$$" << endl;
cout << " |  $$   /$$//$$__  $$| $$  | $$|__  $$__/|_____ $$ | $$_____/| $$_____/" << endl;
cout << "   \\ $$ /$$/| $$  \\ $$| $$  | $$   | $$        /$$/ | $$      | $$" << endl;
cout << "   \\  $$$$/ | $$$$$$$$| $$$$$$$$   | $$       /$$/  | $$$$$   | $$$$$" << endl;
cout << "    \\  $$/  | $$__  $$| $$__  $$   | $$      /$$/   | $$__/   | $$__/ "  << endl;
cout << "     | $$   | $$  | $$| $$  | $$   | $$     /$$/    | $$      | $$    "  << endl;
cout << "     | $$   | $$  | $$| $$  | $$   | $$    /$$$$$$$$| $$$$$$$$| $$$$$$$$" << endl;
cout << "     |__/   |__/  |__/|__/  |__/   |__/   |________/|________/|________/" << endl;
                                                                              
cout << "                           .-------.    ______" << endl;
cout << "                          /   o   /|   /\\     \\" << endl;
cout << "                         /_______/o|  /o \\  o  \\" << endl;
cout << "                         | o     | | /   o\\_____\\" << endl;
cout << "                         |   o   |o/ \\o   /o    /" << endl;
cout << "                         |     o |/   \\ o/  o  /" << endl;
cout << "                         '-------'     \\/____o/" << endl;




                                                                                
    srand(time(NULL));
	cout << endl << endl << endl << endl << endl;
	
	cout << "Would you like to play against a computer? (Enter 1 to play against CPU or 0 to play against another player) ";
	cin >> computer; //user inputs 1 to play against computer, 0 to play against another player
	
	while (cin.fail() || computer>1 || computer<0) { //check on user input for computer variable, if it's not 1 or 0, must choose again
		cin.clear();
		cout << "Invalid. Please enter 1 to play against a computer or 0 to play against another player: ";
		cin.ignore(256, '\n');
		cin >> computer;
	}
	
	cout << "Who is Player 1? (max 10 characters): " << endl;
	cin >> p.p1; //player 1 name
	if (computer!=1) {
		cout << "Who is Player 2? (max 10 characters): " << endl;
		cin >> p.p2; //player 2 name
	}
	else p.p2="Computer"; //sets computer as player 2 name

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
	int kill = 0;
	int sum = 0;
	int pl = 0;
	int player=1;

	while (kill != 1) { //while scorecard is not filled
		
		cout << endl << endl << endl << endl;
		if (player == 1) 
			cout << "It is " << p.p1 << "'s turn!" << endl;
		else
			cout << "It is " << p.p2 << "'s turn!" << endl;
		sum=0;	//reset sum variable
		
		p.cleanPossible(); //resets possible points column
		p.print(); //prints scorecard
		p.roll(computer, player); //roll function
		p.possiblePoints(player); //outputs possible points given current dice
		p.print(); //print scorecard
		p.choose(player, computer); //function where player chooses which square to fill
		player=player+1; //go to next player

		for (int i = 0; i < 5; i ++) //sets die array to 0's
		{
			p.die[i] = 0;
		}

		pl=player%2; //to change which player's turn it is
		if (pl==0) player=2;
		else player=1;


		for (int i=0; i<14; i++) { //to keep track of how many squares have been filled on the scorecard by both players combined
			for (int j=0; j<2; j++) {
				if (p.mask[i][j] == 1)
					sum ++;			
			}
		}

		if (sum == 26) //once all 13 squares have been filled for both players, set variable so that it exits the gameplay while loop
			kill = 1;
	}

	//determine winners
	int total1, total2;
	total1 = p.calculateScore(1,14); //calcs total scores for each player
	total2 = p.calculateScore(2,14);
	
	cout << endl << endl << endl << endl << endl;

	if (total1 > total2) //congratulates player for winning
		cout << "Congratulations " << p.p1 << ", you have won the game!" << endl;
	else if (total2 > total1)	
		cout << "Congratulations " << p.p2 << ", you have won the game!" << endl;
	else
		cout << "Tie game. No winner this time!" << endl;
	
	cout << endl << endl << endl << endl;
}	//end of constructor
