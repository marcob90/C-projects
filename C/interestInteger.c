#include <stdio.h>
#include <math.h>
#define PERSONALS 100000
int main() {
	double rate = 0.05;
	int amount = PERSONALS;
	int years;
	int dollars, cents;
	
	printf("%4s", "Year");
	printf("%15s\n", "Savings");

	/*for(years = 1; years <= 10 ; years++){            // WARNING: this algorithm looks correct but it is dragging the approximation error, due to downcasting, through the cycle
			amount *= 1 + rate;
			dollars = amount / 100;
			cents = amount % 100;
			if(cents >= 10)
				printf("%4d%12d.%d\n", years, dollars, cents);	
			else
				printf("%4d%12d.0%d\n", years, dollars, cents);
	}
	amount = PERSONALS;
	printf("\n");*/
	for(years = 1; years <= 10 ; years++){
			amount = PERSONALS * pow(1 + rate, years);
			dollars = amount / 100;
			cents = amount % 100;
			if(cents >= 10)
				printf("%4d%12d.%d\n", years, dollars, cents);	
			else
				printf("%4d%12d.0%d\n", years, dollars, cents);
	}
	
	return 0;

}
