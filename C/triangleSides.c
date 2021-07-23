#include <stdio.h>

/*Write a program that reads three nonzero float values and determines
and prints if they could represent the sides of a triangle.*/


int main() {
	float sidesArray[3];
	int counter = 0;
	
	while(counter < 3){
		printf("Enter a value: ");
		scanf("%f", &sidesArray[counter]);
		counter++;
	}
	
    if(sidesArray[0] > sidesArray[1]+sidesArray[2] || sidesArray[1] > sidesArray[0]+sidesArray[2] || sidesArray[2] > sidesArray[1]+sidesArray[0])
    	printf("This is not a triangle");
    
	
	else{
		printf("It is a triangle");
	}
    		

	return 0;
}
