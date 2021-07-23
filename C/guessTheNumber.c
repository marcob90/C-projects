#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkGuess(int, int);
int main() {
	int number;
	int guess;
	int status = 0;
	int count = 0;
	
	srand(time(NULL));
	number = rand() % 1000 + 1;
	printf("I have a number between 1 and 1000\nCan you guess my number?\nEnter your first guess\n");
	
	while(status != 1){
		count++;
		scanf("%d", &guess);
		status = checkGuess(guess, number);
	}
	
	printf("You guessed the number in %d guesses", count);
	
	return 0;
}

int checkGuess(int g, int n){
	if(g == n)
		return 1;
	else if(g > n)
		printf("Too high. Try again\n");
	else
		printf("Too low. Try again\n");
		
	return 0;
}
