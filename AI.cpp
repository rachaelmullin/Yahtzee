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

string AI::AIroll(int die[5])
{
	//declare variables
	int counter[6] = {0,0,0,0,0,0};
	int high = 0;
	string c = "";
	string var;
	int val = 0;
	string res;

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

	for (int i = 0; i < 6; i ++)
	{
		if (counter[i] > high && counter[i] > 1)
		{
			high = i + 1;
			for (int i = 0; i < 5; i++)
			{
				if (die[i] == high)
				{
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

int AI::choose(int scorecard[][3])
{
	int v = 1;
	for (int i = 0; i < 14; i ++)
	{
		if (scorecard[i][0] > 24)
		{
			v = 0;
		}	//end if
	}	//end for

	return v;
}	//end choose function

int AI::score(int scorecard[][3], int mask[][2])
{
	//declare variables
	int score = 0;
	int value = 0;
	int kill = 0;

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

	return score;
}	//end of score function
