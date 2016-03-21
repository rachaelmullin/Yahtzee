//Rachael Mullin, Pauline Blatt, Noah Sarkey
//Fund Comp 2 Final Project
//Yahtzee
//functions for ensuring a valid option has been entered on the scorecard

#include <iostream>
using namespace std;


int checkAce(int,int);
int checkTwos(int, int);
int checkThrees(int, int);
int checkFours(int, int);
int checkFives(int, int);
int checkSix(int, int);
int check3ofKind(int, int);
int check4ofKind(int, int);
int checkFullHouse(int, int);
int checkSmStraight(int, int);
int checkLgStraight(int, int);
int checkYahtzee(int, int);
int checkChance(int, int);

int main() {

}

int checkAce(int player, int die[5]) {
//take in die array, check if  valid, compute score for that square on scorecard
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

