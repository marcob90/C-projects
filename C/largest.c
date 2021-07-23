#include <stdio.h>

int main() {
	int number;
	int largest = 0;
	int counter = 0;
	
	while(counter < 10){
		printf("Insert an integer: ");
		scanf("%d", &number);
		if(number > largest){
			largest = number;
		}
		counter++;
		printf("\n");
	}
	
	printf("\n\nThe largest number is %d", largest);
	return 0;
}
