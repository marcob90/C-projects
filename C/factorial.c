#include <stdio.h>
#include <math.h>
#define APPROX 10
#define X 2

int factorial(int n);
double neperNumber(void);
double exponentialFunction(void);

int main() {
	int number;
	
	printf("Enter a number: ");
	scanf("%d", &number);
	
	printf("Factorial of %d is %d\n\n", number, factorial(number));
	
	printf("Neper number approximated till %d is: %lf\n\n", APPROX, neperNumber());
	
	printf("Exponential function calculated in %d is: %lf", X, exponentialFunction());
	return 0;
}

int factorial(int n){
	if(n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

double neperNumber(void){
	int c = 1;
	double neper = 1.0;
	
	while(c <= APPROX){
		neper += 1.0/factorial(c);
		c++;
	}
	return neper;
}

double exponentialFunction(void){
	int c = 1;
	double exp = 1.0;
	
	while(c <= APPROX){
		exp += pow(X,c)/(double)factorial(c);
		c++;
	}
	return exp;
}
