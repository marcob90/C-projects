#include <stdio.h>

int main() {
	int var = 4;
	int value = 8;
	
	printf("Initial value of variable is: %d\n", var);
	printf("Preincremented value of variable is: %d\n", ++var);
	printf("Value of variable after preincrementing is: %d\n", var);
	var = 4;
	printf("Initial value of variable is: %d\n", var);
	printf("Postincremented value of variable is: %d\n", var++);
	printf("Value of variable after postincrementing is: %d\n", var);
	
	return 0;
}
