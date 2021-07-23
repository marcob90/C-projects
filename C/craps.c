#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playCraps(void);
int rollDice(void);
int placeBet(void);

enum Status{
	WON,
	LOST,
	CONTINUE
};

int bankBalance;

int main() {
	bankBalance = 1000;
	
	srand(time(NULL));
	
	printf("***Welcome to Mandalay Bay Casino. Have fun playing Craps!!!***\n\n");
	printf("Your balance is %d\n", bankBalance);
	
	while(bankBalance > 0){
		playCraps();
		printf("\nYour balance is %d\n", bankBalance);
	}
	printf("\nHope to see you soon!");
	return 0;
}

void playCraps(void){
	int sum;
	int myPoints;
	int wager;
	
	enum Status status;
	
	wager = placeBet();
	
	sum = rollDice();
	
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
			printf("Your point is %d\n", myPoints);
			status = CONTINUE;
	}
	
	while(status == CONTINUE){
		sum = rollDice();
		
		if(sum == myPoints)
			status = WON;
		else if(sum == 7)
			status = LOST;
	}
	
	if(status == WON){
		bankBalance += wager;
		printf("You won!\n");
	}
	else{
		bankBalance -= wager;
		printf("You lost\n");
	}
}

int rollDice(void){
	int die1;
	int die2;
	int workSum;
	
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
	workSum = die1 + die2;
	
	printf("Player rolled %d + %d = %d\n", die1, die2, workSum);
	
	return workSum;
}

int placeBet(void){
	int bet = bankBalance + 1;
	
	while(bet > bankBalance){
		printf("Enter your bet: ");
		scanf("%d", &bet);
		if(bet > bankBalance)
			printf("Error! Your bet is greater than your available money. Enter another bet\n");
	}
	
	return bet;
}
