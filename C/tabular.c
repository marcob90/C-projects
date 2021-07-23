#include <stdio.h>

int main() {
	int number = 1;
	
	printf("N\t10*N\t100*N\t1000*N\n");
	while(number <= 10){
		printf("%d\t%d\t%d\t%d\n", number, number*10, number*100, number*1000);
		number++;
	}
	
	number = 3;
	printf("\n\nA\tA+2\tA+4\tA+6\n");
	while(number <= 15){
		printf("%d\t%d\t%d\t%d\n", number, number+2, number+4, number+6);
		number += 3;
	}
	
	return 0;
}
