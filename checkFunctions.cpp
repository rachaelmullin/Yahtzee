//Rachael Mullin, Pauline Blatt, Noah Sarkey
//Fund Comp 2 Final Project
//Yahtzee
//functions for ensuring a valid option has been entered on the scorecard

#include <iostream>
using namespace std;

int checkAce(player) {
//take in die array, check if  valid, compute score for that square on scorecard
	int count=0;
	for (int i=0; i<5; i++) {
		if (die[i]==1) {
			count++;
		}
	}
	scorecard[player][0]=count*1;
}

int checkTwos() {
	int count=0;
	for (int i=0; i<5; i++) {
                if (die[i]==2) {
                        count++;
                }
        }
        scorecard[player][1]=count*1;
}

int checkThrees() {
	int count=0;
        for (int i=0; i<5; i++) {
                if (die[i]==3) {
                        count++;
                }
        }
        scorecard[player][2]=count*1;

}

int checkFours() {
	int count=0;
        for (int i=0; i<5; i++) {
                if (die[i]==4) {
                        count++;
                }
        }
        scorecard[player][3]=count*1;

}

int checkFives() {
	int count=0;
        for (int i=0; i<5; i++) {
                if (die[i]==5) {
                        count++;
                }
        }
        scorecard[player][4]=count*1;
}

int checkSix() {
	int count=0;
        for (int i=0; i<5; i++) {
                if (die[i]==6) {
                        count++;
                }
        }
        scorecard[player][5]=count*1;

}

int check3ofKind() {
	int valid=0;
	for (int i=0; i<5; i++) {
		int count=0;
		for (int j=0; j<5; j++) {
			if (i!=j && die[i]==die[j]) {
				count++;
				valid=die[j];
				
			}
		}
		if (count==2) break;
	}
	if (valid != 0) {
		scorecard[player][8]=valid*3;
	}
	else scorecard[player][8]=0;
}

int check4ofKind() {
	int valid=0;
        for (int i=0; i<5; i++) {
                int count=0;
                for (int j=0; j<5; j++) {
                        if (i!=j && die[i]==die[j]) {
                                count++;
                                valid=die[j];

                        }
                }
                if (count==3) break;
        }
        if (valid != 0) {
                scorecard[player][9]=valid*4;
        }
        else scorecard[player][9]=0;
}

int checkFullHouse() {
	int pair=0, pairNum, triple=0, tripleNum;
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
                			if (count==3) {
						triple=1;
					}
				}
			}
		}
        }
	if (pair=1 && triple==1) {
		scorecard[player][10]=25;
	}
	else scorecard[player][10]=0;
}

int checkSmStraight() {
	
}

int checkLgStraight() {

}

int checkYahtzee() {
	int valid=0;
	for (int i=0; i<5; i++) {
		int count=0;
		for (int j=0; j<5; j++) {
			if (i!=j && die[i]==die[j]) {
				count++;
			}
		}
		if (count==5) {
			valid=1;
		}
	}
	if (valid==1) scorecard[player][13]=50;
	else scorecard[player][13]=0;
}

int checkChance() {
	scorecard[player][14]=die[0]+die[1]+die[2]+die[3]+die[4];
}

