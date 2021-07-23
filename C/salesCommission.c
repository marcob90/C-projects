#include <stdio.h>
#define BASE_SALARY 200.0F
#define PERCENTAGE 0.09F

int main() {
	float sales;
	float salary; 
	
	printf("Enter sales in dollars (-1 to end): ");
	scanf("%f", &sales);
	
	while(sales != -1){
		salary = BASE_SALARY + PERCENTAGE*sales;
		printf("Salary is: $%.2f", salary);
		printf("\n\nEnter sales in dollars (-1 to end): ");
		scanf("%f", &sales);
	}
	return 0;
}
