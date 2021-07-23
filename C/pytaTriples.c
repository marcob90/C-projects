#include <stdio.h>

int main() {
	int side1, side2, hypo;

	printf("Pythagorean Triples\n\n");
	for(side1 = 1; side1 <= 500; side1++)
		for(side2 = 1; side2 <= 500; side2++)
			for(hypo = 1; hypo <= 500; hypo++)
				if(hypo*hypo == side1*side1 + side2*side2)
					printf("%d\t%d\t%d\n", side1, side2, hypo);
			
		
	
	
	return 0;
}
