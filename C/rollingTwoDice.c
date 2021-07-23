#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13

int rollDice(void);
void printResult(const int[], int);
int main(){
	int total;
	int rolls = 1;
	int array[SIZE] = {0};
	
	srand(time(NULL));
	
	while(rolls <= 36000){
		total = rollDice() + rollDice();
		array[total]++;
		rolls++;
	}
	
	printResult(array, SIZE);
	
	return 0;
}

int rollDice(void){
	return rand() % 6 + 1;
}

void printResult(const int a[], int size){
	int i;
	
	printf("%5s%15s\n", "Rolls", "Frequency");
	
	for(i = 2; i < size; i++){
		printf("%5d%15d\n", i, a[i]);
	}
}
