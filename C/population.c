#include <stdio.h>
#define CURRENT_YEAR 2018

//forecast population growth in 5 years
int main() {
	float worldPopulation;
	float growthRate;
	float increase;
	float holder;
	int c = 0; //counter
	
	printf("Enter current world population in billions: ");
	scanf("%f", &worldPopulation);
	printf("\nEnter current world population growth rate (%s): ", "%");
	scanf("%f", &growthRate);
	
	printf("%4s%16s%16s\n\n", "YEAR", "POPULATION", "INCREASE"); 
	holder = worldPopulation;
	while(c <= 75){
		printf("%4d", CURRENT_YEAR+c);
		printf("%16f", worldPopulation);
		printf("%16f M\n", (worldPopulation - holder)*1000);
		holder = worldPopulation;
		worldPopulation *= (growthRate/100 + 1);
		
		c++;
	}
    
	return 0;
}
