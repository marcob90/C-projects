#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 31
#define GAMES 1000

// Write a program that runs 1000 games of craps

void simulateCraps(int[], int[], int);
int rollDice(void);

enum Status{
	WON,
	LOST,
	CONTINUE
};

int main() {
	int count = 1;
	int wonGames[SIZE] = {0};
	int lostGames[SIZE] = {0};
	int totalWon = 0;
	int totalLost = 0;
	float avarageLength = 0.0f;
	
	srand(time(NULL));
	
	while(count <= GAMES){
		simulateCraps(wonGames, lostGames, SIZE);
		count++;
	}
	
	printf("***Craps simulation***\n\n");

	printf("%5s%15s%15s%20s\n\n", "Game", "Won Frequency", "Lost Frequency", "Chance of winning");
	
	for(count = 1; count < SIZE; count++){
		totalWon += wonGames[count];
		totalLost += lostGames[count];
		avarageLength += 1.0f*(wonGames[count]+lostGames[count])*count/GAMES;
		printf("%5d%15d%15d%19.2f%s\n", count, wonGames[count], lostGames[count], 
		(wonGames[count]+lostGames[count] == 0) ? 0.0f : (float)wonGames[count]/(wonGames[count]+lostGames[count])*100, "%");
	}
	
	
	printf("\nTotal won games are %d\nTotal lost games are %d\n", totalWon, totalLost);
	printf("Probabilty to win is %.2f%s\n", (float)totalWon/(totalWon+totalLost)*100, "%");
	printf("The avarage length of a crap game is %.2f", avarageLength);
	

	return 0;
}

void simulateCraps(int w[], int l[], int size){
	int sum;
	int myPoints;
	int countGames = 0;
	
	enum Status status;
	
	sum = rollDice();
	countGames++;
	
	switch(sum){
		case 7:
		case 11:
			status = WON;
		break;
		
		case 2:
		case 3:
		case 12:
			status = LOST;
		break;
		default:
			myPoints = sum;
			status = CONTINUE;
	}
	
	while(status == CONTINUE){
		sum = rollDice();
		countGames++;
		
		if(sum == myPoints)
			status = WON;
		else if(sum == 7)
			status = LOST;
	}
	
	if(status == WON){
		w[countGames]++;
	}
	else{
		l[countGames]++;
	}
}

int rollDice(void){
	int die1;
	int die2;
	int workSum;
	
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
	workSum = die1 + die2;
	
	return workSum;
}
