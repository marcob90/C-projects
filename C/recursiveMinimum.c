#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void recursivePrintArray(const int[], const int);
int recursiveMinimum(const int[], const int);
void initializeArray(int*, const int);

int main(){
	int array[SIZE];
	int minimum;
	
	srand(time(NULL));
	initializeArray(&array[0], SIZE);
	minimum = recursiveMinimum(array, SIZE);
	recursivePrintArray(array, SIZE);
	printf("\n\nMinimum value is: %d", minimum);
	
	return 0;
}

int recursiveMinimum(const int a[], const int size){
	
	if(size > 1)
		return a[size - 1] < recursiveMinimum(a, size - 1) ? a[size - 1] : recursiveMinimum(a, size - 1);
	
	return a[0];
	
}

void recursivePrintArray(const int a[], const int size){
	
	if(size != 0){  //if array has a size greater than 0, print it, exit function otherwise
		if(size > 1)
			recursivePrintArray(a, size - 1);
		
		printf("%4d", a[size - 1]);
	}
	
}

void initializeArray(int a[], const int size){
	int i;
	
	for(i = 0; i < size; i++){
		a[i] = rand() % 100;
	}
}
