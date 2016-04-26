// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// AI.cpp

#include "AI.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string.h>

using namespace std;

AI::AI()
{
	
}	//end of default constructor

//determine which dies to save on each roll
string AI::AIroll(int die[5])
{
	//declare variables
	int counter[6] = {0,0,0,0,0,0};
	int high = 0;
	string c = "";
	string var;
	int val = 0;
	string res;

	//iterate through the die and values to see how many of each there are
	for (int i = 0; i < 6; i ++)
	{
		for (int j = 0; j < 5; j ++)
		{
			if (die[j] == i+1)
			{
				counter[i] ++;
			}	//end if
		}	//end for
	}	//end for

	//iterate through the created array to check if any number has more than 1 die, if so save it
	for (int i = 0; i < 6; i ++)
	{
		if (counter[i] > high && counter[i] > 1)
		{
			high = i + 1;
			for (int i = 0; i < 5; i++)
			{
				if (die[i] == high)
				{
					//determine value and convert to a string to be sent to the program
					val = i+1;
					stringstream convert;
					convert << val;
					res = convert.str();
					c = c + res;
				}	//end if
			}	//end for
		}	//end if
	}

	return c;
}	//end of AIroll function

//decide whether to roll again or accept a score
int AI::choose(int scorecard[][3])
{
	//declare variables (default is roll again)
	int v = 1;

	//iterate through the scorecard possible section to determine if something greater than 24
	for (int i = 0; i < 14; i ++)
	{
		if (scorecard[i][0] > 24)
		{
			v = 0;
		}	//end if
	}	//end for
    
	return v;
}	//end choose function

//determine which score to take
int AI::score(int scorecard[][3], int mask[][2])
{
	//declare variables
	int score = 0;
	int value = 0;
	int kill = 0;

	//see what the highest possible score is
	for (int i = 0; i < 14; i++)
	{
		if (scorecard[i][0] > value)
		{
			if (i < 6)
				score = i + 1;
			if (i > 6)
				score = i;

			value = scorecard[i][0];
		}	//end if
	}	//end for loop

	//picking a value for if there are no possible points to be had with a given turn
	if (score == 0)
	{
		for (int j = 0; j < 14; j ++)
		{
			if (mask[j][1] == 0 && j != 6)
			{
				if (kill != 1)
				{
					score = j;
					kill = 1;
				}	//end if
			}	//end for
		}	//end for	
	}	//end if
    	cout << "CPU picked category: " << score << endl;
	return score;
}	//end of score function
