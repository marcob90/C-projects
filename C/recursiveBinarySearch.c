#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

void initializeArray(int[], const int);
int recursiveBinarySearch(const int[], const int, const int, int, int);
void printArray(const int[], const int);
void bubbleSort(int[], const int);

int main(){
	int array[SIZE];
	int result;
	int searchKey;
	
	srand(time(NULL));
	
	printf("Insert key: ");
	scanf("%d", &searchKey);
	
	initializeArray(array, SIZE);
	bubbleSort(array, SIZE);
	result = recursiveBinarySearch(array, searchKey, SIZE, 0, SIZE - 1);
	
	if(result != -1)
		printf("%d was found at element number %d\n", searchKey, result);
	else
		printf("Element not found\n");
		
	printArray(array, SIZE);	
	return 0;
}

int recursiveBinarySearch(const int a[], const int key, const int size, int low, int high){
	int middle;
	
	middle = low + high / 2;
	
	while(low <= high){
		if(a[middle] == key)
			return middle;
		else if(a[middle < key])
			return recursiveBinarySearch(a, key, size, low, middle - 1);
		return recursiveBinarySearch(a, key, size, middle + 1, high);
	}
	
	return -1;
}

void bubbleSort(int a[], const int size){
	int pass, j;
	int hold;
	
	for(pass = 1; pass < size; pass++){
		for(j = 0; j < size - 1; j++){
			if(a[j] > a[j + 1]){
				hold = a[j + 1];
				a[j + 1] = a [j];
				a[j] = hold;
			}
		}
	}
}

void initializeArray(int a[], const int size){
	int i;
	
	for(i = 0; i < size; i++){
		a[i] = rand() % 100;
	}
}

void printArray(const int a[], const int size){
	int i;
	
	for(i = 0; i < size; i++){
		printf("%4d", a[i]);
	}
}
