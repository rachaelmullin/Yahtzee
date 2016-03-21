// roll.cpp
// testing the roll function to put into the Yahtzee program

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main() {

    int roll=1;
    int die[5];

    while (roll<2) {
        srand(time(NULL));
        
        for (int i=0; i<6; i++) {
            die[i] = rand() % 6 + 1;
            cout << "Die " << i+1 << "= " << die[i] << endl;
        }
        roll++;
        
    }
}

