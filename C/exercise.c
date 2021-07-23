#include <stdio.h>

int main() {
	int var;
	scanf("%d", &var);
	int fiveDigit = var / 10000;
	int fourDigit = var % 10000 / 1000;
	int threeDigit = var % 10000 % 1000 / 100;
	int twoDigit = var % 10000 % 1000 % 100 / 10;
	int oneDigit = var % 10000 % 1000 % 100 % 10;
	
	printf("%d   %d   %d   %d   %d\n", fiveDigit, fourDigit, threeDigit, twoDigit, oneDigit);

    return 0;
    
}
