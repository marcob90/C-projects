#include <stdio.h>

float celsius(float);
float fahreneit(float);
int main() {
	float temperature = .0f;
	int row = 1;
	
	while(row <= 10){
		printf("CELSIUS");
		for(; temperature < 10*row; temperature++){
			printf("%10d", (int)temperature);
		}
		temperature -= 10.0f;
		printf("\nTO\nFAHRENEIT");
		printf("%8.2f", fahreneit(temperature));
		for(temperature++ ; temperature < 10*row; temperature++){
			printf("%10.2f", fahreneit(temperature));
		}
		printf("\n\n");
		row++;
	}
	
	temperature = 32.0f;
	row = 4;
	
	while(row <= 21){
		printf("FAHRENEIT");
		printf("%8d", (int)temperature);
		for(temperature++; temperature <= 10.0f*row + 1.0f; temperature++){
			printf("%10d", (int)temperature);
		}
		temperature -= 10.0f;
		printf("\nTO\nCELSIUS");
		printf("%10.2f", celsius(temperature));
		for(temperature++ ; temperature <= 10.0f*row + 1.0f; temperature++){
			printf("%10.2f", celsius(temperature));
		}
		printf("\n\n");
		row++;
	}
	return 0;
}

float celsius(float t){
	return (t - 32.0f) * 5.0f/9.0f;
}
float fahreneit(float t){
	return t * 9/5 + 32.0f;
}
