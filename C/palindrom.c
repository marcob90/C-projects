#include <stdio.h>

int main() {
	int var;
	int fiveDigit;
	int fourDigit;
	int threeDigit;
	int twoDigit;
	int oneDigit;
	
	printf("Enter a number of five digit: ");
	scanf("%d", &var);
	
	fiveDigit = var / 10000;
	fourDigit = var % 10000 / 1000;
	threeDigit = var % 1000 / 100;
	twoDigit = var % 100 / 10;
	oneDigit = var % 10;
	
	if(fiveDigit == oneDigit && fourDigit == twoDigit)
		printf("Number is palindrome");
	else
		printf("Number is NOT palindrome");
	
	return 0;
}
