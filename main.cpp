// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// main.cpp

#include <iostream>
#include "Game.h"
#include "Scorecard.h"
using namespace std;

int main()
{
	//declare variables
	int gameplay = 1;

	while (gameplay == 1)
	{
		Scorecard a;
		a.print();
	}	//end while loop

	return 0;
}	//end of main function
