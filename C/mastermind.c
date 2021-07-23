#include <stdio.h>
#include <time.h>
#include <string.h>

#define PEGS_NUMBER 4

enum Pegs{
	YELLOW = 1,
	BLUE,
	PINK,
	GREEN,
	BROWN,
	ORANGE
};
enum Pegs pegs;

void createCombinationToGuess(int combination[]);
void printCombination(int combination[]);
void createGuessCombination(int combination[]);

int main(){
	int combinationToGuess[PEGS_NUMBER]; //initial combination
	int userCombination[PEGS_NUMBER]; //user will insert here his guess
	
	createCombinationToGuess(combinationToGuess);
	printCombination(combinationToGuess);
	createGuessCombination(userCombination);
//	printCombination(userCombination);
	
}

void createCombinationToGuess(int combination[]){
	int c; //counter 
	srand(time(NULL)); //makes rand random
	
	for(c=0; c < PEGS_NUMBER; c++)  //assigns to combination a random number between 1 and 6
		combination[c] = rand() % 6 + 1;
	
}

void printCombination(int combination[]){
	int c; //counter 
	
	for(c=0; c < PEGS_NUMBER; c++){
		pegs = combination[c];
		switch(combination[c]){
			case YELLOW:
				printf("YELLOW ");
			break;
			case BLUE:
				printf("BLUE ");
			break;
			case GREEN:
				printf("GREEN ");
			break;
			case PINK:
				printf("PINK ");
			break;
			case BROWN:
				printf("BROWN ");
			break;
			case ORANGE:
				printf("ORANGE ");
			break;
			default:			
			break;
			
		}
	}
	printf("\n");
		
}

void createGuessCombination(int combination[]){
	int c = 1; //counter
	char guess[] = ""; //string that holds what the user typed
	char *guessToken; //token version of string guess
	char *guessArray[4];
	
	printf("To guess, insert 4 colors separated by a space and press ENTER. The available colors are YELLOW, ORANGE, PINK, GREEN, BROWN, BLUE\n");
	scanf("%s", guess);
	
	guessToken = strtok(guess, " ");
	guessArray[0] = guessToken;
    
	while (guessToken != NULL && c < PEGS_NUMBER){
	    guessToken = strtok (NULL, " ");
		guessArray[c] = guessToken;
		c++;
	}
	
	for(c=0; c<PEGS_NUMBER; c++){
		if(!strcmp(guessArray[c], "YELLOW"))
			pegs = YELLOW;
		else if(!strcmp(guessArray[c], "ORANGE"))
			pegs = ORANGE;
		else if(!strcmp(guessArray[c], "PINK"))
			pegs = PINK;
		else if(!strcmp(guessArray[c], "BROWN"))
			pegs = BROWN;
		else if(!strcmp(guessArray[c], "GREEN"))
			pegs = GREEN;
		else if(!strcmp(guessArray[c], "BLUE"))
			pegs = BLUE;
		else
			printf("ERROR!");
	
		combination[c] = pegs;
	}
}
