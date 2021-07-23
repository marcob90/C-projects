#include <stdio.h>

int main() {
	int dimension;
	int row = 1;
	int column;
	
	printf("Insert square dimension: ");
	scanf("%d", &dimension);
	
	while(row <= dimension){
		column = 1;
		if(row % 2 == 0)
			printf(" ");
		while(column <= dimension){
			printf("* ");
			column++;
		}
		
		row++;
		printf("\n");
	}

	return 0;
}
