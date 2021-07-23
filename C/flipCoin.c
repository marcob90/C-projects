#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(void);
int main() {
	int toss;
	int head = 0, cross = 0;
	
	srand(time(NULL));
	for(toss = 1; toss <= 100; toss++){
		if(1 == flip())
			head++;
		else
			cross++;
	}
	
	printf("Head: %d\nCross: %d", head, cross);
	return 0;
}

int flip(void){
	return rand() % 2;
}
