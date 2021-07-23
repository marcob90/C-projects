#include <stdio.h>

int gcd(int, int);

int main(){
	int number1, number2;
	
	printf("Enter an integer number: ");
	scanf("%d", &number1);
	printf("Enter an integer number: ");
	scanf("%d", &number2);
	
	printf("GCD of %d and %d is: %d", number1, number2, gcd(number1, number2));
	return 0;
}

int gcd(int x, int y){
	if(y == 0)
		return x;
	else{
		return gcd(y, x % y);
	}
}
