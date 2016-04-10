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
	string name2 = "Not Rachael";

	cout << "______________________________________________________________" << endl;
	cout << "\t\t\t" << "Possible Points" << "\t" << name1 << "\t" << name2 << endl;
	cout << "______________________________________________________________" << endl;
	cout << "1. Aces (1s) \t\t" << scorecard[0][0] << "\t" << scorecard[1][0] << "\t" << scorecard[2][0] << endl;
	cout << "2. Twos (2s) \t\t" << scorecard[0][1] << "\t" << scorecard[1][1] << "\t" << scorecard[2][1] << endl;
	cout << "3. Threes (3s) \t\t" << scorecard[0][2] << "\t" << scorecard[1][2] << "\t" << scorecard[2][2] << endl;
	cout << "4. Fours (4s) \t\t" << scorecard[0][3] << "\t" << scorecard[1][3] << "\t" << scorecard[2][3] << endl;
	cout << "5. Fives (5s) \t\t" << scorecard[0][4] << "\t" << scorecard[1][4] << "\t" << scorecard[2][4] <<  endl;
	cout << "6. Sixes (6s) \t\t" << scorecard[0][5] << "\t" << scorecard[1][5] << "\t" << scorecard[2][5] << endl;
	cout << "Total Score \t\t" << calculateScore(1,6) << "\t" << calculateScore(2,6) << endl;
	giveBonus(1);
	giveBonus(2);
	cout << "Bonus \t\t\t" << scorecard[1][6] << "\t" << scorecard[2][6] << endl;
	cout << "Total Score \t\t" << calculateScore(1,7) << "\t" << calculateScore(2,7) << endl;
	cout << "______________________________________________________________" << endl;
	cout << "7. 3 of a Kind (Total value of dice) \t" << scorecard[0][7] << "\t" << scorecard[1][7] << "\t" << scorecard[2][7] << endl;
	cout << "8. 4 of a Kind (Total value of dice) \t" << scorecard[0][8] << "\t" << scorecard[1][8] << "\t" << scorecard[2][8] << endl;
	cout << "9. Full House (35 pts) \t\t" << scorecard[0][9] << "\t" << scorecard[1][9] << "\t" << scorecard[2][9] << endl;
	cout << "10. Small Straight (30 pts) \t\t" << scorecard[0][10] << "\t" << scorecard[1][10] << "\t" << scorecard[2][10] << endl;
	cout << "11. Large Straight (40 pts) \t\t" << scorecard[0][11] << "\t" << scorecard[1][11] << "\t" << scorecard[2][11] << endl;
	cout << "12. Yahtzee! (50 pts) \t\t" << scorecard[0][12] << "\t" << scorecard[1][12] << "\t" << scorecard[2][12] << endl;
	cout << "13. Chance (Sum of all dice) \t\t" << scorecard[0][13] << "\t" << scorecard[1][13] << "\t" << scorecard[2][13] << endl;
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
