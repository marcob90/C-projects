#include <stdio.h>

#define SIZE 20

void stringReverse(const char[], int);

int main(){
	char string[] = "ilovec";
	int index = 0; //starting point of string to invert
	
	stringReverse(string, index);
	
	return 0;
}

void stringReverse(const char s[], int i){
	
		if(s[i] != '\0'){
			stringReverse(s, i + 1);
			printf("%c", s[i]);
		}
		
}

