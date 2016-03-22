// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Participants.cpp

#include "Participants.h"
#include <iostream>
#include <iomanip>
#include <string>
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
