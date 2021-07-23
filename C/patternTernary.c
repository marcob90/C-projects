#include <stdio.h>
#define N 20

int main() {
	int row = N;
	int column;
	
	while(row >= 1){
		column = 1;
		
		while(column <= N){
			printf("%s", row % 2 ? "<" : ">");
			column++;
		}
		row--;
		printf("\n");
	}
	
	return 0;
}
