#include <stdio.h>

float calculateCharges(float);
void printTotal(float [], float []);
int main() {
	int customer;
	float hours[4];
	float money[4];
	
	for(customer = 1; customer <= 3; customer++){
		printf("Enter hours parked for customer %d: ", customer);
		scanf("%f", &hours[customer]);
	}
	printf("Car%12s%12s\n", "Hours", "Charge");
	for(customer = 1; customer <= 3; customer++){
		money[customer] = calculateCharges(hours[customer]);
		printf("%d%14.1f%11.2f$\n", customer, hours[customer], money[customer]);
	}
	
	printTotal(money, hours);
	
	return 0;
}

float calculateCharges(float time){
	float charge = 2.0f;
	
	if(time <= 3.0f)
		return charge;
	
	charge += 0.5f*(time - 3.0f);
		
	if(charge > 10.0f)
		return 10.0f;
	
	return charge;
}

void printTotal(float charge[4], float time[4]){
	int count;
	float totalCharge = 0;
	float totalTime = 0;
	
	for(count = 1; count <= 3; count++){
		totalCharge += charge[count];
		totalTime += time[count];
	}
	printf("TOTAL%10.2f%11.2f$", totalTime, totalCharge);	
}
