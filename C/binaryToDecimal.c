#include <stdio.h>
#include <assert.h>

int main() {
	int binary;
	int decimal = 0;
	int digit = 1;
	int remainder = 10;
	int n = 2;
	int power = 1;
	int singleDigit;
	printf("Enter a binary number: ");
	scanf("%d", &binary);
	
	while(digit <= 10){
		
		assert(remainder != 0);
		singleDigit = (binary % remainder / (remainder/10));
		
		assert(singleDigit == 0 || singleDigit == 1);
		
		decimal += singleDigit * power;
		digit++;
		remainder *= 10;
		power *= 2;
		
	}
	
	printf("\n\n%d -> %d", binary, decimal);

	return 0;
    
}
