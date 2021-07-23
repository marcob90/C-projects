#include <stdio.h>

void displaySquare(int, char);
int main() {
	int dimension;
	char character;
	
	printf("Enter character: ");
	if((character = getchar()) != EOF){
		printf("Enter dimension: ");
		scanf("%d", &dimension);
		
		displaySquare(dimension, character);
	}	
	return 0;
}

void displaySquare(int side, char fillCharacter){
	int row, column;
	for(row = 1; row <= side; row++){
		for(column = 1; column <= side; column++){
			printf("%c", fillCharacter);
		}
		printf("\n");
	}
}
