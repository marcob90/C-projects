#include <stdio.h>

int main() {
	double gallons;
	double miles;
	double totalGallons = 0.0;
	double totalMiles = 0.0;
	
	printf("Enter the gallons used (-1 to end): ");
	scanf("%lf", &gallons);
	
	while(gallons != -1){
		totalGallons += gallons;
		printf("Enter the miles driven: ");
		scanf("%lf", &miles);
		totalMiles += miles;
		printf("The miles / gallon for this tank was %lf\n\n", miles/gallons);
		printf("Enter the gallons used (-1 to end): ");
		scanf("%lf", &gallons);
	}
	
	printf("\nThe overall average miles/gallon was %lf", totalMiles/totalGallons);
	
	return 0;
}
