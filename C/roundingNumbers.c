#include <stdio.h>
#include <math.h>

void rounfToInteger(float);
void rounfToTenth(float);
void rounfToHundredth(float);
void rounfToThousandth(float);
int main() {
	float number;
	
	while(1){
		printf("Enter a real number: ");
		scanf("%f", &number);
		
		rounfToInteger(number);
		rounfToTenth(number);
		rounfToHundredth(number);
		rounfToThousandth(number);
	}	
	
	return 0;
}

void rounfToInteger(float n){
	printf("\n%f rounded to integer is %d\n\n", n, (int)floor(n + .5));
}
void rounfToTenth(float n){
	printf("\n%f rounded to tenth is %.3f\n\n", n, floor(n*10 + .5)/10);
}
void rounfToHundredth(float n){
	printf("\n%f rounded to hundredth is %.3f\n\n", n, floor(n*100 + .5)/100);
}
void rounfToThousandth(float n){
	printf("\n%f rounded to thousandth is %.3f\n\n", n, floor(n*1000 + .5)/1000);
}
