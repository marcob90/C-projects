#include <stdio.h>

int main() {
	int number = 1;
	
	while(number <= 10){
		printf("%s", number % 2 ? "****" : "++++++++");
		number++;
	}
	
	return 0;
}
