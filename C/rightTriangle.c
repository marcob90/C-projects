#include <stdio.h>

/*Write a program that reads three nonzero integers and determines
and prints if they could be the sides of a right triangle. */


int main() {
    int sidesArray[3];
	int counter = 0;
	
	while(counter < 3){
		printf("Enter a value: ");
		scanf("%d", &sidesArray[counter]);
		counter++;
	}
	
    if(sidesArray[0]*sidesArray[0]==sidesArray[1]*sidesArray[1] + sidesArray[2]*sidesArray[2])
    	printf("This is a right triangle");
    else if(sidesArray[1]*sidesArray[1]==sidesArray[0]*sidesArray[0] + sidesArray[2]*sidesArray[2])
    	printf("This is a right triangle");
    else if(sidesArray[2]*sidesArray[2]==sidesArray[1]*sidesArray[1] + sidesArray[0]*sidesArray[0])
    	printf("This is a right triangle");
    else
    	printf("This is NOT a right triangle");

    		

	return 0;
}
