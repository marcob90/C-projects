#include <stdio.h>

int main() {
	int dimension;
	int row;
	int column;
	
	printf("Insert square dimension: ");
	scanf("%d", &dimension);
	row = dimension;
	while(row >= 1){
		column = 1;
		
		while(column <= dimension){
			printf("*\t");
			column++;
		}
		
		row--;
		printf("\n");
	}
	printf("\n\n");
	row = dimension;
	while(row >= 1){
		column = 1;
		
		printf("*");
		while(column <= dimension - 2){
			if(row == dimension || row == 1)
				printf("*");
			else
				printf(" ");
			column++;
		}
		printf("*");
		
		row--;
		printf("\n");
	}
	
	
	
	return 0;
}
