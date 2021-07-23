#include <stdio.h>

int main(){
	static int count = 0;
	printf("%d\n", count);
	while(count<=10000){

		count++;
		main();
	}
	return 0;
}
