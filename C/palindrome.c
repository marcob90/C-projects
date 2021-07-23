#include <stdio.h>

int checkPalindrome(const char[], const int, int);
int getStringSize(const char[]);
void ignorePunctuation(char[], const int);

int main(){
	char sentence[] = "l'unul";
	char originalSentence[] = "l'unul";
	int isPalindrome;
	int index = 0;
    
    ignorePunctuation(sentence, getStringSize(sentence));
	isPalindrome = checkPalindrome(sentence, getStringSize(sentence), index);
	
	if(isPalindrome)
		printf("'%s' is palindrome", originalSentence);
	else
		printf("'%s' is not palindrome", originalSentence);
	
	return 0;
}

int checkPalindrome(const char s[], const int size, int i){
	
	while(i < size - i - 2){

		if(s[i] == s[size - i - 2])
			return checkPalindrome(s, size, i + 1);
		
		return 0;
	}	
	
	return 1;
}

int getStringSize(const char s[]){
	int i = 0;
	
	while(s[i] != '\0')
		i++;
	
	return i + 1; //size includes final character '\0'
}

void ignorePunctuation(char s[], const int size){
	int i, j;
	int counter = 0;
	
	while(counter < size - 1){
		for(i = 0; s[i] != '\0'; i++)
			if(s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == ';' || s[i] == '\'')
				for(j = i; s[j] != '\0'; j++)
					s[j] = s[j+1];
		
		counter++;
	}
}

