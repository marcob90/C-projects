#include <stdio.h>

int main() {
	int number;
	int firstLargest = 0;
	int secondLargest = 0;
	int counter = 0;
	
	while(counter < 10){
		printf("Insert an integer: ");
		scanf("%d", &number);
		if(number > firstLargest){
			secondLargest = firstLargest;
			firstLargest = number;
		}
		counter++;
		printf("\n");
	}
	
	printf("\n\nThe largest numbers are %d and %d", firstLargest, secondLargest);
	return 0;
}
