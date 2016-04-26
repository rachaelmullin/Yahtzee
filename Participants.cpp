// Pauline Blatt, Rachael Mullin, Noah Sarkey
// Final Project
// Participants.cpp - contains the roll function, point checking functions, and scorecard functions

#include "Participants.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "AI.h"

using namespace std;

// constructor
Participants::Participants()
{
    // initializes the mask
    mask[6][0] = 0;
    mask[6][1] = 0;
}	//end of default constructor

// print the scorecard
void Participants::print()
{
    cout << "______________________________________________________________" << endl;
    cout << "\t\t\t" << "Possible" << "\t" << p1 << "\t" << p2 << endl;
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
    cout << "Total Score \t\t\t\t" << calculateScore(1,14) << "\t" << calculateScore(2,14) << endl;
}	//end of print function

// calculate total score from dice array
int Participants::calculateScore(int player, int high) {
   
    //declare variables
    int sum = 0;

    for (int i = 0; i < high; i++)
    {
        sum = sum + scorecard[i][player]; // adds values of scorecard to find total score
    }	//end for loop

    return sum;
}	//end of calculateScore function

// determine if player attained bonus
void Participants::giveBonus(int player)
{
    // declare variables
    int bonus = 0;

    if (calculateScore(player,6) >= 63) // if total score of top half of scorecard is greater than 63
    {
        bonus = 35; // gives bonus
    }

    scorecard[6][player] = bonus;
}	//end of giveBonus function

// roll function
void Participants::roll(int cpu, int player)
{
    // declare variables
    int computer = cpu;
    int roll=1, next;
    string save;
    int savedDie[5] = {0, 0, 0, 0, 0}; // die numbers player saved
    int savedDieValue[5] = {0, 0, 0, 0, 0}; // values of dies player saved
    int bad=0, nosave=0;

    // ROLL 1
    cout << endl;
    cout << "Roll 1!" << endl;
    
    // rolls 5 random dice with values 1-6
    for (int i=0; i<5; i++) {
        die[i] = rand() % 6 + 1;
        cout << "Die " << i+1 << " = " << die[i] << endl; // prints dice
    }
    cout << endl;

    // determine which die will be saved for either human or computer player
    if (computer != 1 || player == 1) // human
    {
        cout << "What die(s) do you want to save? If you don't want to save any, enter 'n'. No spaces. ";
        cin >> save; // saves die numbers as a string
    }	//end if
    
    else if (computer == 1) // computer
    {
        cout << "CPU Entered: ";
        save = a.AIroll(die); // run function to see which die AI should save
        cout << save << endl;
    }	 //end else

    // error checking to see if valid saved die
    for (int i=0; i<save.length(); i++) {  
        if (save[i]=='n') nosave=1; // player chose not to save any
        if (save[i]!='n' && (save[i]>'5' || save[i]<'1')) { 
            bad=1; // invalid option
        }	//end if
    }	//end for

    // error checking and then saving the correct die
    while (bad==1) { // outputs error message
        cout << "You have entered an invalid die. Please choose again." << endl;
        cout << "What die(s) do you want to save? If you don't want to save any, enter 'n'. No spaces. ";
        cin >> save;
        cout << endl;
        for (int i=0; i<save.length(); i++) {
            if (save[i]=='n') nosave=1; // player chooses to not save any
            if (save[i]!='n' && (save[i]>'5' || save[i]<'1')) {
                bad=1; // invalid option
            }	//end if
            else bad=0; // valid option
        }	//end for
    }	//end while

    // convert save string into int array
    for (int i=0; i<save.length(); i++) { 
        savedDie[i] = save[i] - '0';
    }	//end for
    cout << endl;

    if (nosave!=1) { // player chooses to save die
        
        // inputs the saved die's values into its own array for future use
        for (int i=0; i<5; i++) {
            if (savedDie[i] != 0) {
                savedDieValue[savedDie[i]-1] = die[savedDie[i]-1]; // creates savedDieValue array
            }	//end if
        }	//end for

        // output saved die
        cout << "Saved Dice..." << endl;
        for (int i=0; i<5; i++) {
            if (savedDie[i] != 0) {
                cout << "Die " << savedDie[i] << " = " << die[savedDie[i]-1] << endl;
            }	//end if
        }	///end for
        cout << endl;

        // output unsaved die
        cout << "Unsaved die..." << endl;
        for (int i=0; i<5; i++) {
            if (savedDieValue[i] == 0) {
                cout << "Die " << i+1  << " = " << die[i] << endl;
            }	//end if
        }	//end for
        cout << endl;

        // Determine if player wants to roll again
        if (player == 1 || computer != 1) // human player
        {
            // prompt user to roll again
            cout << "Next roll? Input 1 for yes, 0 for no: ";
            cin >> next;

            // error checking for invalid entry of next
            while (cin.fail() || next>1 || next<0) {
                cin.clear();
                cout << "Invalid entry. Please pick 1 or 0." << endl;
                cout << "Next roll? Input 1 for yes, 0 for no: ";
                cin.ignore(256, '\n');
                cin >> next;
                cout << endl;
            }	//end while
        }	//end if

        else if (computer == 1) // CPU calculates if it should roll again
        {
            next = a.choose(scorecard);
        }	//end else
    }	//end if

    else // player chooses not to save 
    {
        next=1; // automatically goes to next turn
        for (int i=0; i<5; i++) { // changes values of all saved die to 0
            savedDie[i]=0;
        }	//end for
    }	//end else

    // ROLL 2 and 3
    while (next==1 && roll<=2) { // next roll but not 3rd roll
        roll++; // increment roll          
        cout << "Roll " << roll << "! Let's roll!" << endl;

        // outputs new dice rolls
        cout << "New dice..." << endl;
        for (int i=0; i<5; i++) {
            if (savedDieValue[i] == 0) {
                die[i] = rand() % 6 + 1;
                cout << "Die " << i+1 << " = " << die[i] << endl;
            }	//end if
        }	//end for
        cout << endl;

        // outputs dice you chose to save
        cout << "Saved dice..." << endl; 
        for (int i=0; i<5; i++) {
            if (savedDie[i] != 0) {
                cout << "Die " << savedDie[i] << " = " << die[savedDie[i]-1] << endl;
            }	//end if
        }	//end for
        cout << endl;

        // resetting saved die arrays
        for (int i=0; i<5; i++) {
            savedDie[i] = 0; // initialize to 0
            savedDieValue[i] = 0; // initialize to 0
        }	//end for

        save = ' '; // reset save
        nosave=0; // reset nosave
        bad = 0;

        // Determines which dice player wants to save
        if (roll!=3) { // asks which ones you want to save unless its the last roll
            
            if (player == 1 || computer != 1) // human player
            {
                cout << "What die(s) do you want to save? If you don't want to save any, enter 'n'. No spaces. ";
                cin >> save; // saves as a string
            }	//end if
            
            else if (computer == 1) // CPU 
            {
                cout << "CPU Entered: " << endl;
                save = a.AIroll(die); // function to determine which die to save
                cout << save << endl;
            }	//end else

            // error checking to see if invalid entry for save    
            for (int i=0; i<save.length(); i++) {
                if (save[i]=='n') nosave=1; // does not save any
                if (save[i]!='n' && (save[i]>'5' || save[i]<'1')) {
                    bad=1; // invalid entry
                }	//end if
            }	//end for
        
            // Invalid entry for save
            while (bad==1) { // displays error message
                cout << "You have entered an invalid die. Please choose again." << endl;
                cout << "What die(s) do you want to save? If you don't want to save any, enter 'n'. No spaces. ";
                cin >> save;
                cout << endl;
                for (int i=0; i<save.length(); i++) { // asks again to enter value for save
                    if (save[i]=='n') nosave=1;				  
                    if (save[i]!='n' && (save[i]>'5' || save[i]<'1')) {
                        bad=1; // invalid entry
                    }	//end if
                    else bad=0; // valid entry
                }	//end for
            }	//end while

            // converting string to int array       
            for (int i=0; i<save.length(); i++) {
                savedDie[i] = save[i] - '0';
            }	//end for
        }
        
        else if (nosave==1) { // player chooses not to save any
            for (int i=0; i<5; i++) {
                savedDie[i]=0; // initializes savedDie array
            }	//end for
        }	//end if

        if (nosave==0) { // player chooses to save

            // place saved die values into savedDieValue array
            for (int i=0; i<5; i++) {
                if (savedDie[i] != 0) {
                    savedDieValue[savedDie[i]-1] = die[savedDie[i]-1];
                }	//end if
            }	//end for
            cout << endl;

            // output saved die
            cout << "Saved Die..." << endl;
            for (int i=0; i<5; i++) { // outputs saved dice
                if (savedDie[i] != 0) {
                    cout << "Die " << savedDie[i] << " = " << die[savedDie[i]-1] << endl;
                }	//end if
            }	//end for
            cout << endl;

            // output unsaved die
            cout << "Unsaved die..." << endl;
            for (int i=0; i<5; i++) {
                if (savedDieValue[i] == 0) {
                    cout << "Die " << i+1  << " = " << die[i] << endl;
                }	//end if
            }	//end for
            cout << endl;

            // if not the third roll, asks player if they want to roll again 
            if (roll!=3) {
                if (computer != 1 || player == 1) // human player
                {
                    cout << "Next roll? Input 1 for yes, 0 for no: ";
                    cin >> next;
                }	//end if
                
                else // CPU
                {
                    next = a.choose(scorecard); // determines if the CPU should roll again
                }	//end else
            }	//end if

            // Error checking for invalid next entry
            while (cin.fail() || next>1 || next<0) {
                cin.clear();
                cout << "Invalid entry. Please pick 1 or 0." << endl;
                cout << "Next roll? Input 1 for yes, 0 for no: ";
                cin.ignore(256, '\n');
                cin >> next;
                cout << endl;
            }	//end while
        }	//end if
    }	//end if
    //end while
    
    // outputs dice
    cout << "Your dice are: " << endl;
    for (int i=0; i<5; i++) {
        cout << "Die " << i+1 << " = " << die[i] << endl;
    }	//end for

    // prompt user to pick score
    cout << "Now pick a score!" << endl;

}	//end of roll function

// determines ones score
int Participants::checkAce() {
    int count=0, total;
    for (int i=0; i<5; i++) {
        if (die[i]==1) {
            count++; // number of ones
        }
    }
    total=count;
    return total;
}	//end of checkAce function

// determines twos score
int Participants::checkTwos() {
    int count=0, total;
    for (int i=0; i<5; i++) {
        if (die[i]==2) {
            count++; // number of twos
        }
    }
    total=count*2; // twos score
    return total;
}	//end of checkTwos function

// determines threes score
int Participants::checkThrees() {
    int count=0, total;
    for (int i=0; i<5; i++) {
        if (die[i]==3) {
            count++; // number of threes
        }
    }
    total=count*3; // threes score
    return total;
}	//end of checkThrees function

// determines fours score
int Participants::checkFours() {
    int count=0, total;
    for (int i=0; i<5; i++) {
        if (die[i]==4) {
            count++; // number of fours
        }
    }
    total=count*4; // fours score
    return total;
}	//end of checkFours function

// determines fives score
int Participants::checkFives() {
    int count=0, total;
    for (int i=0; i<5; i++) {
        if (die[i]==5) {
            count++; // number of fives
        }
    }
    total=count*5; // fives score
    return total;
}	//end of checkFives function

// determines sixes score
int Participants::checkSix() {
    int count=0, total;
    for (int i=0; i<5; i++) {
        if (die[i] == 6) {
            count++; // number of sixes
        }
    }
    total=count*6; // sixes score
    return total;
}	//end of checkSix function

// determines 3 of a kind score
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
            total=total+die[i]; // calculating 3 of a kind score
        }
    }
    else total=0;
    return total;
}	//end of check3ofKind function

// determines 4 of a kind score
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
            total=total+die[i]; // calculating 4 of a kind score
        }
    }
    else total=0;
    return total;
}	//end of check4ofKind function

// determines full house score
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

                        }	//end if
                    }	//end for
                    if (count==2) {
                        triple=1;
                    }	//end if
                }	//end for
            }	//end if
        }	//end for
    }	//end for
    if (pair=1 && triple==1) {
        total=25; // full house score given
    }	//end if
    else total=0;
    return total;
}	//end of checkFullHouse function

// determines small straight score
int Participants::checkSmStraight() {
    int count=0, total, temp, valid;
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
        if ((die[i]==die[i+1]-1) || (die[i]==die[i+1])) {
            valid=1;
            if (die[i]!=die[i+1]) count++;
            if (count==3) break;
        }
        else {
            valid=0;
            break;
        }
    }
    if (valid==0) {
        count=0;
        for (int i=1; i<4; i++) {
            if (die[i]==die[i+1]-1 || die[i]==die[i+1]) {
                valid=1;
                if (die[i]!=die[i+1]) count++;
            }
            else {
                valid=0;
                break;
            }
        }
    }
    if (valid==1 && (count==3 || count==4)) total=30;
    else total=0;
    return total;
}	//end of checkSmStraight function

// determines large straight score
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
}	//end of checkLgStraight function

// determines yahtzee score
int Participants::checkYahtzee() {
    int total, valid=0;
    for (int i=0; i<5; i++) {
        int count=0;
        for (int j=0; j<5; j++) {
            if (i!=j && die[i]==die[j]) {
                count++;
            }	//end if
        }	//end for
        if (count==4) {
            valid=1;
        }	//end if
    }	//end for
    if (valid==1) total=50;
    else total=0;
    return total;
}	//end of checkYahtzee function

// determiens chance score
int Participants::checkChance() {
    int total = 0;
    total = die[0]+die[1]+die[2]+die[3]+die[4]; // adds values of all dice
    return total;
}	//end of checkChance function

// fill possible column on the scorecard using all the check functions
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

    // fills possibles column with 0 if category already taken 
    for (int i=0; i<14; i++) {
        if (mask[i][player-1] != 0) 
        {
            scorecard[i][0] = 0;
        }	//end if
    }	//end for
}	//end of possiblePoints function

// function used to input user/CPU choice and fill scorecard 
void Participants::choose(int player, int computer) 
{
    //declare variables
    int choice;
    int change = 0;

    while (change == 0)	
    {	
        if (player == 1 || computer != 1) // human player
        {
            // prompts user for what category it would like to fill
            cout << "Which category would you like to fill? ";
            cin >> choice; // takes in choice
        }	//end if
        
        else // CPU player
        {
            choice = a.score(scorecard, mask); // AI function to determine what category it should pick 
        }	//end else

        // error checking, invalid input for choice
        if (cin.fail()) {
            cout << "Invalid choice. Please pick a category 1-13." << endl;
            cin.clear();
            cin.ignore(256, '\n');
            change=0; // run while loop again
        }

        else { // fills upper half of scorecard
            if (mask[choice-1][player-1]==0 && choice>=1 && choice<=6) 
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

                }	//end switch
                mask[choice-1][player-1] = 1;
                change = 1;	
            }	//end if
         
            // fills lower half of scorecard
            else if (mask[choice][player-1] == 0 && choice >= 7 && choice < 14)
            {
                switch(choice-1) {
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
                }	//end switch
                mask[choice][player-1] = 1;
                change = 1;
            }	//end else if
            
            // error checking, invalid option for choice
            else if (cin.fail() || choice > 13 || choice < 1) {
                cout << "This is an invalid option. Please pick another option: ";
                cin.clear();
                cin.ignore(256, '\n');
                change=0; // run while loop again
            }

            else // already filled option
                cout << "You have already filled this option. Please select another." << endl;
        }	//end while
    }
}	//end of main function

// initializes possibles column 
void Participants::cleanPossible()
{
    for (int i = 0; i < 14; i ++)
    {
        scorecard[i][0] = 0;
    }	//end for	
}	//end of cleanPossible function
