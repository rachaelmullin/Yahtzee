// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Participants.cpp

#include "Participants.h"
//#include "Scorecard.h"
//#include "Scorecard.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

Participants::Participants()
{



}	//end of default constructor

void Participants::print()
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

int Participants::calculateScore(int player, int high)
{
	//declare variables
	int sum = 0;

	for (int i = 0; i < high; i++)
	{
		sum = sum + scorecard[player][i];
	}	//end for loop

	return sum;
}	//end of calculateScore function



void Participants::giveBonus(int player)
{
	//declare variables
	int bonus = 0;

	if (calculateScore(player,6) >= 63)
	{
		bonus = 35;
	}

	scorecard[player][6] = bonus;
}	//end of giveBonus function

void Participants::roll()
{
    int roll=1, next;
    int die[5]; // simulates the dice
    string save;
    int savedDie[6] = {0, 0, 0, 0, 0, 0};
    int savedDieValue[6] = {0, 0, 0, 0, 0, 0};

    srand(time(NULL));
    cout << endl;
    cout << "Roll 1!" << endl;

    for (int i=0; i<6; i++) { // first roll, outputs 6 random dice
        die[i] = rand() % 6 + 1;
        cout << "Die " << i+1 << " = " << die[i] << endl;
    }
    cout << endl;
    cout << "What die(s) do you want to save? No spaces. ";

    cin >> save; // saves die numbers as a string

    //  save.erase(std::remove(save.begin(), save.end(), ' '), save.end()); // eliminating spaces...not working
	 for (int i=0; i<save.length(); i++) { // converting string to int array
        savedDie[i] = save[i] - '0';
    }

    cout << endl;

    for (int i=0; i<6; i++) { // inputs the saved die's values into its own array for future use
        if (savedDie[i] != 0) {
            savedDieValue[savedDie[i]-1] = die[savedDie[i]-1];
        }
    }

    // output saved die
	 cout << "Saved Dice..." << endl;

    for (int i=0; i<6; i++) { // outputs saved dice
        if (savedDie[i] != 0) {
            cout << "Die " << savedDie[i] << " = " << die[savedDie[i]-1] << endl;
        }
    }
    cout << endl;

    // output unsaved die
    cout << "Unsaved die..." << endl;
    for (int i=0; i<6; i++) {
        if (savedDieValue[i] == 0) {
            cout << "Die " << i+1  << " = " << die[i] << endl;
        }
    }
    cout << endl;

    // prompt user to roll again
     cout << "Next roll? Input 1 for yes, 0 for no: ";
    cin >> next;
    cout << endl;

    while (next==1 && roll<=2) { // second and third rolls

        roll++; // increment roll          
        cout << "Roll " << roll << "! Let's roll!" << endl;

        cout << "New dice..." << endl;
        for (int i=0; i<6; i++) { // outputs new dice rolls
            if (savedDieValue[i] == 0) {
                die[i] = rand() % 6 + 1;
                cout << "Die " << i+1 << " = " << die[i] << endl;
            }
        }
        cout << endl;

        cout << "Saved dice..." << endl;
        for (int i=0; i<6; i++) { // outputs saved dice
            if (savedDie[i] != 0) {
                cout << "Die " << savedDie[i] << " = " << die[savedDie[i]-1] << endl;
            }
        }
        cout << endl;

        // resetting saved die arrays
       for (int i=0; i<6; i++) {
            savedDie[i] = 0;
            savedDieValue[i] = 0;
        }
        save = ' ';

        if (roll!=3) { // asks which ones you want to save unless its the last roll
            cout << "What die(s) do you want to save? No spaces. ";

            cin >> save; // saves as a string

            //  save.erase(std::remove(save.begin(), save.end(), ' '), save.end()); // eliminating spaces...not working
         for (int i=0; i<save.length(); i++) { // converting string to int array
                savedDie[i] = save[i] - '0';
            }

            for (int i=0; i<6; i++) {
                if (savedDie[i] != 0) {
                    savedDieValue[savedDie[i]-1] = die[savedDie[i]-1];
                }
            }
            cout << endl;

            // output saved die
         cout << "You saved..." << endl;

            for (int i=0; i<6; i++) { // outputs saved dice
                if (savedDie[i] != 0) {
                    cout << "Die " << savedDie[i] << " = " << die[savedDie[i]-1] << endl;
                }
            }
            cout << endl;

            // output unsaved die
           cout << "Unsaved die..." << endl;
            for (int i=0; i<6; i++) {
                if (savedDieValue[i] == 0) {
                    cout << "Die " << i+1  << " = " << die[i] << endl;
                }
            }
            cout << endl;
            cout << "Dice 6 = " << die[5] << endl;

            if (roll!=3) {
                cout << "Next roll? Input 1 for yes, 0 for no: ";
                cin >> next;
                cout << endl;
            }
        }
    }

    cout << "Your dice are: " << endl;
    for (int i=0; i<6; i++) {
        cout << "Die " << i+1 << " = " << die[i] << endl;
    }
    cout << "Now pick a score!" << endl;

}	//end of roll function

int Participants::checkAce() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==1) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int Participants::checkTwos() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==2) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int Participants::checkThrees() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==3) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int Participants::checkFours() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==4) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int Participants::checkFives() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==5) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int Participants::checkSix() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==6) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int Participants::check3ofKind() {
        int valid=0, total;
        for (int i=0; i<5; i++) {
                int count=0;
                for (int j=0; j<5; j++) {
                        if (i!=j && die[i]==die[j]) {
                                count++;
                        }
                }
                if (count==2) {
                        valid=die[i];
                        break;
                }
        }
        if (valid != 0) {
                total=valid*3;
        }
        else total=0;
        return total;
}

int Participants::check4ofKind() {
        int valid=0, total;
        for (int i=0; i<5; i++) {
                int count=0;
                for (int j=0; j<5; j++) {
                        if (i!=j && die[i]==die[j]) {
                                count++;
                        }
                }
                if (count==3) {
                        valid=die[i];
                        break;
                }
        }
        if (valid != 0) {
                total=valid*4;
        }
        else total=0;
        return total;
}

int Participants::checkFullHouse() {
        int total, pair=0, pairNum, triple=0, tripleNum;
        for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                        if (i!=j && die[i]==die[j]) {
                                pair=1;
                                pairNum=die[j];
                                for (int i=0; i<5; i++) {
                                        int count=0;
                                        for (int j=0; j<5; j++) {
                                                if (i!=j && die[i]==die[j] && die[j]!=pairNum) {
                                                        count++;

                                                }
                                        }
                                        if (count==2) {
                                                triple=1;
                                        }
                                }
                        }
                }
        }
        if (pair=1 && triple==1) {
                total=25;
        }
        else total=0;
        return total;
}

int Participants::checkSmStraight() {
        int total, temp, valid;
        for (int j=0; j<5; j++) {
                for (int k=0; k<5; k++) {
                        if (die[j]<die[k]) {
                                temp=die[j];
                                die[j]=die[k];
                                die[k]=temp;
                        }
                }
        }
        for (int i=0; i<4; i++) {
                if (die[i]==die[i+1]+1) valid=1;
                else valid=0;
        }
        if (valid==0) {
                for (int i=1; i<5; i++) {
                        if (die[i]==die[i+1]+1) valid=1;
                        else valid=0;
                }
        }
        if (valid==1) total=30;
        else total=0;
        return total;
}

int Participants::checkLgStraight() {
        int total, temp, valid;
        for (int j=0; j<5; j++) {
                for (int k=0; k<5; k++) {
                        if (die[j]<die[k]) {
                                temp=die[j];
                                die[j]=die[k];
                                die[k]=temp;
                        }
                }
        }
        for (int i=0; i<4; i++) {
                if (die[i]==(die[i+1]-1)) valid=1;
                else valid=0;
        }
        if (valid==1) total=40;
        else total=0;
        return total;
}

int Participants::checkYahtzee() {
        int total, valid=0;
        for (int i=0; i<5; i++) {
                int count=0;
                for (int j=0; j<5; j++) {
                        if (i!=j && die[i]==die[j]) {
                                count++;
                        }
                }
                if (count==4) {
                        valid=1;
                }
        }
        if (valid==1) total=50;
        else total=0;
        return total;
}

int Participants::checkChance() {
        int total=die[0]+die[1]+die[2]+die[3]+die[4];
        return total;
}

void Participants::possiblePoints(int player) {
	scorecard[0][0]=checkAce();
	scorecard[0][1]=checkTwos();
	scorecard[0][2]=checkThrees();
	scorecard[0][3]=checkFours();
	scorecard[0][4]=checkFives();
	scorecard[0][5]=checkSix();
	scorecard[0][7]=check3ofKind();
	scorecard[0][8]=check4ofKind();
	scorecard[0][9]=checkFullHouse();
	scorecard[0][10]=checkSmStraight();
	scorecard[0][11]=checkLgStraight();
	scorecard[0][12]=checkYahtzee();
	scorecard[0][13]=checkChance();	

	for (int i=0; i<14; i++) {
		if (mask[player-1][i]!=0) scorecard[0][i]=0;
	}
}

void Participants::choose(int player) {
	int choice;
	cout << "Which square would you like to fill?";
	cin >> choice;

	if (mask[player-1][choice]==0 && choice>=0 && choice<=13) {
		switch(choice) {
			case 0:
				scorecard[player][0] = scorecard[0][0];
				break;
			case 1:
				scorecard[player][1] = scorecard[0][1];
				break;
			case 2:
				scorecard[player][2] = scorecard[0][2];
				break;
			case 3:
				scorecard[player][3] = scorecard[0][3];
				break;
			case 4:
				scorecard[player][4] = scorecard[0][4];
				break;
			case 5:
				scorecard[player][5] = scorecard[0][5];
				break;
			case 6:
				scorecard[player][6] = scorecard[0][6];	
				break;
			case 7:
				scorecard[player][7] = scorecard[0][7];	
				break;
			case 8:
				scorecard[player][8] = scorecard[0][8];	
				break;
			case 9:
				scorecard[player][9] = scorecard[0][9];	
				break;
			case 10:
				scorecard[player][10] = scorecard[0][10];	
				break;
			case 11:
				scorecard[player][11] = scorecard[0][11];	
				break;
			case 12:
				scorecard[player][12] = scorecard[0][12];	
				break;
			case 13:
				scorecard[player][13] = scorecard[0][13];	
				break;	
		}
	}
}	
