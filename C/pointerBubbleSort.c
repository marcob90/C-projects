#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 25

void initArray(int*, const int);
void printArray(const int*, const int);
void bubbleSort(int *const, const int);

int main(){
	int array[SIZE]; //array to sort
	
	initArray(array, SIZE); //generate a random array of size SIZE
	
	printf("Original array sequence is:\n");
	printArray(array, SIZE); //print original array
	
	bubbleSort(array, SIZE);
	printf("Sorted array sequence is:\n");
	printArray(array, SIZE); //print sorted array
	
	return 0;
}

void bubbleSort(int *const aPtr, const int size){
	int pass; //count passes 
	int i; //counter to go through the array
	int hold; //keeps the value 
	int swaps = 0; //count swaps to improve performances
	int holdPass; //holds value of passes
	
	for(pass = 1; pass < size; pass++){
		
		for(i = 0; i < size - pass; i++){
			
			if(*(aPtr + i) > *(aPtr + i + 1)){ //swap two elements
				
				hold = *(aPtr + i);
				*(aPtr + i) = *(aPtr + i + 1);
				*(aPtr + i + 1) = hold;
				swaps++;
			}
		}
		if(swaps == 0){
			break;
		}
		else
			swaps = 0;
	}
	printf("\nSorting was over at pass = %d thanks to enhanced bubbleSort algorithm\n\n", pass);
}

void initArray(int *aPtr, const int size){
	int count; //counter to go through the array
	
	srand(time(NULL));
	
	//generate a random array
	for(count = 0; count < size; count++){
		*aPtr = rand() % 100;
		aPtr++;
	}
}

void printArray(const int *aPtr, const int size){
	int count; //counter to go through the array
	
	//print
	for(count = 0; count < size; count++){
		printf("%4d", *aPtr);
		aPtr++;
	}
	printf("\n");
}
