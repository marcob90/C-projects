#include <stdio.h>
#define DIM 16

int main() {
	int line, spaces, asterisk;
	
	for(line = 1; line <= DIM; line++){
		for(spaces = 1; spaces <= DIM - line; spaces++){
			printf(" ");
		}
		for(asterisk = 1; asterisk <= 2*line - 1; asterisk++){
			printf("*");
		}
		printf("\n");
	}
	
	for(line = 1; line <= DIM-1; line++){
		for(spaces = 1; spaces <= line; spaces++){
			printf(" ");
		}
		for(asterisk = 1; asterisk <= 2*(DIM-line) - 1; asterisk++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
