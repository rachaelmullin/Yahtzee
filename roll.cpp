// roll.cpp
// testing the roll function to put into the Yahtzee program

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;

int main() {

    int roll=1, next;
    int die[5];
    string save;
    int savedDie[6] = {0, 0, 0, 0, 0, 0};
    int savedDieValue[6] = {0, 0, 0, 0, 0, 0};

    srand(time(NULL));

    for (int i=0; i<6; i++) {
        die[i] = rand() % 6 + 1;
        cout << "Die " << i+1 << " = " << die[i] << endl;
    }

    roll++;
    cout << "What die(s) do you want to save? No spaces. ";

    cin >> save;

    save.erase(std::remove(save.begin(), save.end(), ' '), save.end()); // eliminating spaces...not working

    for (int i=0; i<save.length(); i++) { // converting string to int array
        savedDie[i] = save[i] - '0';
    }

    for (int i=0; i<6; i++) { // places values in new array
        savedDieValue[i] = die[savedDie[i]-1];
    }

    cout << endl;
    cout << "You saved..." << endl;

    for (int i=0; i<6; i++) { // outputs saved dice
        if (savedDieValue[i] != 0) {
            cout << "Die " << savedDie[i] << " = " << savedDieValue[i] << endl;
        }
    }

    cout << "Next roll? Input 1 for yes, 0 for no: " << endl;
    cin >> next;

    if (next=1) { // next roll
        

    }


}

