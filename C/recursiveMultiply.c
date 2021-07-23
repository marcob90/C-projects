#include <stdio.h>

int multiply(int, int);
int main() {
	int x, y;
	
	printf("Enter 2 numbers:\n");
	scanf("%d", &x);
	scanf("%d", &y);
	
	if(y >= 0)
		printf("%d * %d is equal to %d", x, y, multiply(x,y));
	else
		printf("%d * %d is equal to %d", x, y, multiply(-x,-y));	
	return 0;
}

int multiply(int a, int b){
	if(1 == b)
		return a;
	else if(0 == b)
		return 0;
	else
		return a + multiply(a, b-1);
}
