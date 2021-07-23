#include <stdio.h>

int main() {
	int i = 0;
	
	while(i<=3000000){
		if(i % 1000000 == 0)
			printf("%d\n", i);
		i++;
	}
	i=1;
	while(1){
		printf("%d\n", 1000*i);
		i++;
	}
	return 0;
}
