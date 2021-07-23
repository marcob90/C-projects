#include <stdio.h>

int main() {
	register int count;
	register double value = 0;
	
	printf("***Approximation of PI***\n\n");
	printf("Number of terms%15s\n", "Value");
	
	for(count = 0; count < 10000000; count++){
		printf("%15d", count+1);
		if(0 == count % 2)
			value += 4.0/(2*count+1);
		else
			value -= 4.0/(2*count+1);
		printf("%15.10lf\n", value);
	}
	return 0;
}
