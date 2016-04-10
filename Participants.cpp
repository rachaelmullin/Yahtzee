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

int checkAce(int player, int die[5]) {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==1) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int checkTwos(int player, int die[5]) {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==2) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int checkThrees(int player, int die[5]) {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==3) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int checkFours(int player, int die[5]) {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==4) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int checkFives(int player, int die[5]) {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==5) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int checkSix(int player, int die[5]) {
        int count=0, total;
        for (int i=0; i<5; i++) {
                if (die[i]==6) {
                        count++;
                }
        }
        total=count*1;
        return total;
}

int check3ofKind(int player, int die[2]) {
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

int check4ofKind(int player, int die[5]) {
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

int checkFullHouse(int player, int die[5]) {
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

int checkSmStraight(int player, int die[5]) {
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

int checkLgStraight(int player, int die[5]) {
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

int checkYahtzee(int player, int die[5]) {
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

int checkChance(int player, int die[5]) {
        int total=die[0]+die[1]+die[2]+die[3]+die[4];
        return total;
}
