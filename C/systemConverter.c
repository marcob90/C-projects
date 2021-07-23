#include <stdio.h>

void printHexaDigit(int n);
int main() {
	int count;
	int dividend, remainder, binary, octal, hexa;
	printf("%7s%15s%15s%15s\n", "Decimal","Binary", "Octal", "Hexa");
	
	for(count = 0; count <= 256; count++){
		printf("\n%7d", count);
		
		printf("%6s", " ");
		remainder = count;
		for(dividend = 256; dividend >= 1; dividend /= 2){
			binary = remainder / dividend;
			printf("%d", binary);
			remainder %= dividend;
		}
		
		printf("%12s", " ");
		remainder = count;
		for(dividend = 64; dividend >= 1; dividend /= 8){
			octal = remainder / dividend;
			printf("%d", octal);
			remainder %= dividend;
		}
		
		printf("%12s", " ");
		remainder = count;
		for(dividend = 256; dividend >= 1; dividend /= 16){
			hexa = remainder / dividend;
		    printHexaDigit(hexa);
			remainder %= dividend;
		}
	}
	return 0;
    
}

void printHexaDigit(int n){
	switch(n){
		case 10:
			printf("A");
		break;
		case 11:
			printf("B");
		break;
		case 12:
			printf("C");
		break;
		case 13:
			printf("D");
		break;
		case 14:
			printf("E");
		break;
		case 15:
			printf("F");
		break;
		default:
			printf("%d", n);
	}
}

