#include <stdio.h>
#include <assert.h>

//smallest number, first is the amount entered 
int main() {
	int amount;
	int i = 1;
	int number, smallest;
	
	scanf("%d", &amount);
	assert(amount > 0);
	scanf("%d", &number);
	smallest = number;
	for(; i < amount; i++){
		scanf("%d", &number);
		if(number < smallest)
			smallest = number;
	}
	
	printf("Smallest number is: %d", smallest);
	return 0;
}
