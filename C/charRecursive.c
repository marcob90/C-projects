#include <stdio.h>


int main() {
	int c;
	
	printf("Enter character: ");
	c = getchar();

	if(c != EOF){
		getchar();
		main();
		printf("%c", c);
	}	
	return 0;
}

