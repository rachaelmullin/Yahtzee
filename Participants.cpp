// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Participants.cpp

#include "Participants.h"
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

	scorecard[6][0] = 0;	

	//declare variables
	string name1 = "Noah";
	string name2 = "Not Rachael";

	cout << "______________________________________________________________" << endl;
	cout << "\t\t\t" << "Possible" << "\t" << name1 << "\t" << name2 << endl;
	cout << "______________________________________________________________" << endl;
	cout << "1. Aces (1s) \t\t" << scorecard[0][0] << "\t\t" << scorecard[0][1] << "\t" << scorecard[0][2] << endl;
	cout << "2. Twos (2s) \t\t" << scorecard[1][0] << "\t\t" << scorecard[1][1] << "\t" << scorecard[1][2] << endl;
	cout << "3. Threes (3s) \t\t" << scorecard[2][0] << "\t\t" << scorecard[2][1] << "\t" << scorecard[2][2] << endl;
	cout << "4. Fours (4s) \t\t" << scorecard[3][0] << "\t\t" << scorecard[3][1] << "\t" << scorecard[3][2] << endl;
	cout << "5. Fives (5s) \t\t" << scorecard[4][0] << "\t\t" << scorecard[4][1] << "\t" << scorecard[4][2] <<  endl;
	cout << "6. Sixes (6s) \t\t" << scorecard[5][0] << "\t\t" << scorecard[5][1] << "\t" << scorecard[5][2] << endl;
	cout << "Total Score \t\t\t\t" << calculateScore(1,6) << "\t" << calculateScore(2,6) << endl;
	giveBonus(1);
	giveBonus(2);
	cout << "Bonus \t\t\t\t\t" << scorecard[6][1] << "\t" << scorecard[6][2] << endl;
	cout << "Total Score \t\t\t\t" << calculateScore(1,7) << "\t" << calculateScore(2,7) << endl;
	cout << "______________________________________________________________" << endl;
	cout << "7. 3 of a Kind \t\t" << scorecard[7][0] << "\t\t" << scorecard[7][1] << "\t" << scorecard[7][2] << endl;
	cout << "8. 4 of a Kind \t\t" << scorecard[8][0] << "\t\t" << scorecard[8][1] << "\t" << scorecard[8][2] << endl;
	cout << "9. Full House \t\t" << scorecard[9][0] << "\t\t" << scorecard[9][1] << "\t" << scorecard[9][2] << endl;
	cout << "10. Small Straight \t" << scorecard[10][0] << "\t\t" << scorecard[10][1] << "\t" << scorecard[10][2] << endl;
	cout << "11. Large Straight \t" << scorecard[11][0] << "\t\t" << scorecard[11][1] << "\t" << scorecard[11][2] << endl;
	cout << "12. Yahtzee! \t\t" << scorecard[12][0] << "\t\t" << scorecard[12][1] << "\t" << scorecard[12][2] << endl;
	cout << "13. Chance \t\t" << scorecard[13][0] << "\t\t" << scorecard[13][1] << "\t" << scorecard[13][2] << endl;
	cout << "Total Score \t\t\t\t" << calculateScore(1,13) << "\t" << calculateScore(2,13) << endl;
}	//end of print function

int Participants::calculateScore(int player, int high) {
	//declare variables
	int sum = 0;

	for (int i = 0; i < high; i++)
	{
		sum = sum + scorecard[i][player];
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

	scorecard[6][player] = bonus;
}	//end of giveBonus function

void Participants::roll()
{
    int roll=1, next;
    //int die[5]; // simulates the dice
    string save;
    int savedDie[5] = {0, 0, 0, 0, 0};
    int savedDieValue[5] = {0, 0, 0, 0, 0};

    srand(time(NULL));
    cout << endl;
    cout << "Roll 1!" << endl;

    for (int i=0; i<5; i++) { // first roll, outputs 5 random dice
        die[i] = rand() % 5 + 1;
        cout << "Die " << i+1 << " = " << die[i] << endl;
    }
    cout << endl;
    cout << "What die(s) do you want to save? No spaces. ";

    cin >> save; // saves die numbers as a string
	 
	 int bad=0;
	 for (int i=0; i<save.length(); i++) {
		if (save[i]>'5' || save[i]<'1') {
			bad=1;
		}
	 }
	 while (bad==1) {
		cout << "You have entered an invalid die. Please choose again." << endl;
		cout << "What die(s) do you want to save? No spaces. ";
		cin >> save;
		cout << endl;
        	for (int i=0; i<save.length(); i++) {
         	       if (save[i]>5+'0' || save[i]<1+'0') {
                        bad=1;
                       }
		       else bad=0;
        	}
	 }

	for (int i=0; i<save.length(); i++) { // converting string to int array
        	savedDie[i] = save[i] - '0';
    	}

    cout << endl;

    for (int i=0; i<5; i++) { // inputs the saved die's values into its own array for future use
        if (savedDie[i] != 0) {
            savedDieValue[savedDie[i]-1] = die[savedDie[i]-1];
        }
    }

    // output saved die
	 cout << "Saved Dice..." << endl;

    for (int i=0; i<5; i++) { // outputs saved dice
        if (savedDie[i] != 0) {
            cout << "Die " << savedDie[i] << " = " << die[savedDie[i]-1] << endl;
        }
    }
    cout << endl;

    // output unsaved die
    cout << "Unsaved die..." << endl;
    for (int i=0; i<5; i++) {
        if (savedDieValue[i] == 0) {
            cout << "Die " << i+1  << " = " << die[i] << endl;
        }
    }
    cout << endl;

    // prompt user to roll again
     cout << "Next roll? Input 1 for yes, 0 for no: ";
    cin >> next;
    cout << endl;
    
    while (next>1 || next<0) {
	cout << "Invalid entry. Please pick 1 or 0." << endl;
	cout << "Next roll? Input 1 for yes, 0 for no: ";
	cin >> next;
	cout << endl;
    }

    while (next==1 && roll<=2) { // second and third rolls

        roll++; // increment roll          
        cout << "Roll " << roll << "! Let's roll!" << endl;

        cout << "New dice..." << endl;
        for (int i=0; i<5; i++) { // outputs new dice rolls
            if (savedDieValue[i] == 0) {
                die[i] = rand() % 5 + 1;
                cout << "Die " << i+1 << " = " << die[i] << endl;
            }
        }
        cout << endl;

        cout << "Saved dice..." << endl;
        for (int i=0; i<5; i++) { // outputs saved dice
            if (savedDie[i] != 0) {
                cout << "Die " << savedDie[i] << " = " << die[savedDie[i]-1] << endl;
            }
        }
        cout << endl;

        // resetting saved die arrays
       for (int i=0; i<5; i++) {
            savedDie[i] = 0;
            savedDieValue[i] = 0;
        }
        save = ' ';

        if (roll!=3) { // asks which ones you want to save unless its the last roll
            cout << "What die(s) do you want to save? No spaces. ";

            cin >> save; // saves as a string

	 int bad=0;
         for (int i=0; i<save.length(); i++) {
                if (save[i]>'5' || save[i]<'1') {
                        bad=1;
                }
         }
         while (bad==1) {
                cout << "You have entered an invalid die. Please choose again." << endl;
                cout << "What die(s) do you want to save? No spaces. ";
                cin >> save;
                cout << endl;
        	for (int i=0; i<save.length(); i++) {
                       if (save[i]>'5' || save[i]<'1') {
                        bad=1;
                       }
                       else bad=0;
                }
 
	 }


         for (int i=0; i<save.length(); i++) { // converting string to int array
                savedDie[i] = save[i] - '0';
            }

            for (int i=0; i<5; i++) {
                if (savedDie[i] != 0) {
                    savedDieValue[savedDie[i]-1] = die[savedDie[i]-1];
                }
            }
            cout << endl;

            // output saved die
         cout << "You saved..." << endl;

            for (int i=0; i<5; i++) { // outputs saved dice
                if (savedDie[i] != 0) {
                    cout << "Die " << savedDie[i] << " = " << die[savedDie[i]-1] << endl;
                }
            }
            cout << endl;

            // output unsaved die
            cout << "Unsaved die..." << endl;
            for (int i=0; i<5; i++) {
                if (savedDieValue[i] == 0) {
                    cout << "Die " << i+1  << " = " << die[i] << endl;
                }
            }
            cout << endl;

            if (roll!=3) {
                cout << "Next roll? Input 1 for yes, 0 for no: ";
                cin >> next;
                cout << endl;
            }

	    while (next>1 || next<0) {
        	cout << "Invalid entry. Please pick 1 or 0." << endl;
        	cout << "Next roll? Input 1 for yes, 0 for no: ";
        	cin >> next;
        	cout << endl;
    	    }

        }
    }

    cout << "Your dice are: " << endl;
    for (int i=0; i<5; i++) {
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
        total=count;
        return total;
}

int Participants::checkTwos() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==2) {
                        count++;
                }
        }
        total=count*2;
        return total;
}

int Participants::checkThrees() {

	for (int i = 0; i < 5; i++)
		cout << die[i] << endl;
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==3) {
                        count++;
                }
		cout << "COUNT" << count << endl;
        }
        total=count*3;
        return total;
}

int Participants::checkFours() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==4) {
                        count++;
                }
        }
        total=count*4;
        return total;
}

int Participants::checkFives() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==5) {
                        count++;
                }
        }
        total=count*5;
        return total;
}

int Participants::checkSix() {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==6) {
                        count++;
                }
        }
        total=count*6;
        return total;
}

int Participants::check3ofKind() {
        int valid=0, total=0;
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
		for (int i=0; i<5; i++) {
                	total=total+die[i];
		}
        }
        else total=0;
        return total;
}

int Participants::check4ofKind() {
        int valid=0, total=0;
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
          	for (int i=0; i<5; i++) {
		      total=total+die[i];
		}
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
                if (die[i]==die[i+1]-1) valid=1;
                else {
			valid=0;
			break;
		}
        }
        if (valid==0) {
                for (int i=1; i<5; i++) {
                        if (die[i]==die[i+1]-1) valid=1;
                        else {
				valid=0;
                		break;
			}
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
                else {
			valid=0;
			break;
		}
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
        int total = 0;
	total = die[0]+die[1]+die[2]+die[3]+die[4];
        return total;
}

void Participants::possiblePoints(int player) {
	scorecard[0][0]=checkAce();
	scorecard[1][0]=checkTwos();
	scorecard[2][0]=checkThrees();
	scorecard[3][0]=checkFours();
	scorecard[4][0]=checkFives();
	scorecard[5][0]=checkSix();
	scorecard[7][0]=check3ofKind();
	scorecard[8][0]=check4ofKind();
	scorecard[9][0]=checkFullHouse();
	scorecard[10][0]=checkSmStraight();
	scorecard[11][0]=checkLgStraight();
	scorecard[12][0]=checkYahtzee();
	scorecard[13][0]=checkChance();	

	for (int i=0; i<14; i++) {
		if (mask[i][player-1]!=0) scorecard[i][0]=0;
	}
}

void Participants::choose(int player) 
{
	int choice;
	cout << "Which square would you like to fill? ";
	cin >> choice;

	if (mask[choice][player-1]==0 && choice>=0 && choice<=13) 
	{
		switch(choice-1) {
			case 0:
				scorecard[0][player] = scorecard[0][0];
				break;
			case 1:
				scorecard[1][player] = scorecard[1][0];
				break;
			case 2:
				scorecard[2][player] = scorecard[2][0];
				break;
			case 3:
				scorecard[3][player] = scorecard[3][0];
				break;
			case 4:
				scorecard[4][player] = scorecard[4][0];
				break;
			case 5:
				scorecard[5][player] = scorecard[5][0];
				break;
			case 6:
				scorecard[7][player] = scorecard[7][0];	
				break;
			case 7:
				scorecard[8][player] = scorecard[8][0];	
				break;
			case 8:
				scorecard[9][player] = scorecard[9][0];	
				break;
			case 9:
				scorecard[10][player] = scorecard[10][0];	
				break;
			case 10:
				scorecard[11][player] = scorecard[11][0];	
				break;
			case 11:
				scorecard[12][player] = scorecard[12][0];	
				break;
			case 12:
				scorecard[13][player] = scorecard[13][0];	
				break;	
		}
	}
}	//end of main function
