#include <stdio.h>

//function that reverse string input
void reverseString(char *str){
	char *end = str;
	
	//find end of string
	if(str){
		while(*end){
			end++;
		}
		//pointer should point to last char != '\0'
		end--;
	}
	
	//swap characters
	while(str < end){
		*str = *str ^ *end;
		*end = *str ^ *end;
		*str = *str ^ *end;
		
		*str++;
		*end--;
	}	
}

int main(){
	char string[] = "supercalifragilistichespiralidoso";
	reverseString(string);
	printf("%s", string);
}
