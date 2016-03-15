// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Scorecard.cpp

#include <iostream>
#include <string>
#include "Scorecard.h"
using namespace std;

Scorecard::Scorecard()
{

	print();

}	//end constructor

int Scorecard::calculateScore(int player, int high)
{
	//declare variables
	int sum = 0;

	for (int i = 0; i < high; i++)
	{
		sum = sum + scorecard[player][i];
	}	//end for loop

	return sum;
}	//end of calculateScore function

void Scorecard::print()
{
	//declare variables
	string name1 = "Noah";
	string name2 = "Rachael";

	cout << "______________________________________________________________" << endl;
	cout << "\t\t\t" << name1 << "\t" << name2 << endl;
	cout << "______________________________________________________________" << endl;
	cout << "Aces (1s) \t\t" << scorecard[0][0] << "\t" << scorecard[1][0] << endl;
	cout << "Twos (2s) \t\t" << scorecard[0][1] << "\t" << scorecard[1][1] << endl;
	cout << "Threes (3s) \t\t" << scorecard[0][2] << "\t" << scorecard[1][2] << endl;
	cout << "Fours (4s) \t\t" << scorecard[0][3] << "\t" << scorecard[1][3] << endl;
	cout << "Fives (5s) \t\t" << scorecard[0][4] << "\t" << scorecard[1][4] << endl;
	cout << "Sixes (6s) \t\t" << scorecard[0][5] << "\t" << scorecard[1][5] << endl;
	cout << "Total Score \t\t" << calculateScore(0,6) << "\t" << calculateScore(1,6) << endl;
	giveBonus(0);
	giveBonus(1);
	cout << "Bonus \t\t\t" << scorecard[0][6] << "\t" << scorecard[1][6] << endl;
	cout << "Total Score \t\t" << calculateScore(0,7) << "\t" << calculateScore(1,7) << endl;
	cout << "______________________________________________________________" << endl;
}	//end of print function

void Scorecard::giveBonus(int player)
{
	//declare variables
	int bonus = 0;

	if (calculateScore(player,6) >= 63)
	{
		bonus = 35;
	}

	scorecard[player][6] = bonus;
}	//end of giveBonus function
