#include <stdio.h>

int power(int, int);
int main() {
	int base = 4, exponent = 4, number;
	
	number = power(base, exponent);
	
	printf("%d elevated to %d is %d", base, exponent, number);
	return 0;
}

int power (int b, int e){
	if(1 == e)
		return b;
	return b * power(b, e-1);
}
