#include <stdio.h>
#include <math.h>

int prime(int);

int main() {
	int number = 3;
	
	printf("1 is prime\n");
	printf("2 is prime\n");
	while(number <= 100000){
		if(prime(number) == 1){
			printf("%d is prime\n", number);
		}
		
		number += 2;
	}
	return 0;
}

int prime(int n){
	int count;
	
	for(count = 3; count <= (int)sqrt(n); count += 2)
		if(n % count == 0)
			return 0;
	
	return 1;
}
