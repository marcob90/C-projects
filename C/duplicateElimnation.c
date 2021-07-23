#include <stdio.h>

#define SIZE 20

void printArray(const int[], int);
int linearSearch(const int[], int, int);
int main(){
	int array[SIZE] = {0};
	int i;
	int newValue = 0;
	int count = 0;
	int result;
	
	for(i = 0; i < SIZE; i++){
		while(newValue < 10 || newValue > 100){
			printf("Insert a number between 10 and 100 included: ");
			scanf("%d", &newValue);
			if(newValue < 10 || newValue > 100)
				printf("Value is not correct\n");
		}
		result = linearSearch(array, newValue, SIZE);
		if(result == -1){
			array[count] = newValue;
			count++;
		}
		newValue = 0;
	}
	
	printArray(array, SIZE);
	
	return 0;
}
int linearSearch(const int a[], int key, int size){
	int i;
	
	for(i = 0; i < size; i++){
		if(a[i] == key)
			return i;
	}
	
	return -1;
}

void printArray(const int a[], int size){
	int count; //counter to go through the array
	
	//print
	for(count = 0; count < size; count++){
		printf("%4d", a[count]);
	}
	printf("\n");
}
