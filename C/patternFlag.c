#include <stdio.h>

int main() {
	int c, count;
	
	for(c=1; c<=10; c++){
		for(count = 1; count <= c; count++){
			printf("*");
		}
		printf("\n");
	}
	
	for(c=10; c>=1; c--){
		for(count = 1; count <= c; count++){
			printf("*");
		}
		printf("\n");
	}
	
	for(c=0; c<10; c++){
		for(count = 1; count <= c; count++){
			printf(" ");
		}
		for(count = 1; count <= 10-c; count++){
			printf("*");
		}
		printf("\n");
	}
	
	for(c=1; c<=10; c++){
		for(count = 1; count <= 10-c; count++){
			printf(" ");
		}
		for(count = 1; count <= c; count++){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
