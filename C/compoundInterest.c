#include <stdio.h>
#include <math.h>
#define PERSONALS 1000.0
int main() {
	double rate = 5.0;
	double amount = PERSONALS;
	int years, c;
	
	printf("%4s", "Year");
	for(c = 0; c <= 5; c++){
		printf("%15s (%d%s)", "Savings", (int)rate+c, "%");
	}
	
	for(years = 1; years <= 10 ; years++){
		printf("\n%4d", years);
		for(c = 0; c <= 5; c++){
			amount = PERSONALS * pow(1 + (rate+c)/100, years);
			printf("%20.2lf", amount);
		}	
	}
	
	return 0;
}
