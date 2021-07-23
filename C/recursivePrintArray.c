#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void recursivePrintArray(int[], const int);
void initializeArray(int[], const int);

int main(){
	int array[SIZE];
	
	srand(time(NULL));
	initializeArray(array, SIZE);
	recursivePrintArray(array, SIZE);
	
	return 0;
}

void recursivePrintArray(int a[], const int size){
	
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
