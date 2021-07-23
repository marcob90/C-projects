#include <stdio.h>

int perfect(int);
void printFactors(int);
int main() {
	int number = 2;
	
	while(number <= 10000){
		if(perfect(number) == 1){
			printf("%d is perfect: ", number);
			printFactors(number);
		}
		
		number += 2;
	}
	return 0;
}

int perfect (int n){
	int sum = 0;
	int count;
	
	for(count = 1; count <= n/2; count++)
		if(n % count == 0)
			sum += count;
	
	if(sum == n)
		return 1;
	
	return 0;
}
void printFactors(int n){
	int count; 
	
	for(count = 1; count <= n/2; count++)
		if(n % count == 0)
			if(count != n/2)
				printf("%d + ", count);
			else
				printf("%d = %d", count, n);
	
	printf("\n");
}
