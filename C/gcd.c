#include <stdio.h>

int gcd(int, int);
int smallest(int, int);
int main(){
	int num1 = 6832, num2 = 3444;
	
	printf("The GCD of %d and %d is: %d", num1, num2, gcd(num1, num2));
	return 0;
}

int gcd(int a, int b){
	int small;
	int great;
	int count;
	
	great = a;
	
	small = smallest(a, b);
	if(small == a)
		great = b;
	
	if(great % small == 0)
		return small;
		
	for(count = small/2 - 1; count > 1; count--)
		if(small % count == 0 && great % count == 0)
			return count;
	
	return 1;
}

int smallest(a, b){
	if(a < b)
		return a;
	
	return b;
}
