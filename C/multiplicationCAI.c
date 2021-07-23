#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define QUESTIONS 10

int a;
int b;
int operation, selectEntry;

void generateQuestion(int);
void generatePositiveAnswer(void);
void generateNegativeAnswer(void);
void calculateResult(int);
int selectDifficultyLevel(void);
void selectOperation(void);
int checkResult(int);

int main(){
	int result;
	int count = 1;
	int wrongAnswers = 0;
	int difficulty;
	int operation;
	
	
	while(1){
		
		selectOperation();
		difficulty = selectDifficultyLevel();
		
		while(count <= QUESTIONS){
			generateQuestion(difficulty);
			scanf("%d", &result);
			/*while(result != a*b){
				generateNegativeAnswer();
				scanf("%d", &result);
			}*/
			if(!checkResult(result)){
				printf("Wrong\n\n");
				wrongAnswers++;
			}
			else
				generatePositiveAnswer();
			count++;
		}
		calculateResult(wrongAnswers);
		count = 1;
	}
	
	
	
	return 0;
}

void generateQuestion(int d){
	int count = 1;
	int digits = 1;
	int temp;
	
	srand(time(NULL));
	
	while(count <= d){
		digits *= 10;
		count ++;
	}
	
	a = rand() % digits;
	b = rand() % digits;
	
	if(selectEntry == 4){
		operation = rand() % 3 + 1;
	}
	
	switch(operation){
		case 1:
			printf("How much is %d plus %d? ", a, b);
		break;
		case 2:
			if(a < b){
				temp = a;
				a = b;
				b = temp;
			}
			printf("How much is %d minus %d? ", a, b);
		break;
		case 3:
			printf("How much is %d times %d? ", a, b);
		break;
		default:
			assert("Error 001. Invalid operation\n");
	}
}

void generatePositiveAnswer(void){
	int answer;
	
	srand(time(NULL));
	
	answer = rand() % 4 + 1;
	
	switch(answer){
		case 1:
			printf("Very good");
		break;
		case 2:
			printf("Excellent");
		break;
		case 3:
			printf("Nice work!");
		break;
		case 4:
			printf("Keep up the good work!");
		break;
		default:
			assert("Something got wrong. Please reboot");
	}
	printf("\n\n");
}

void generateNegativeAnswer(void){
	int answer;
	
	answer = rand() % 4 + 1;
	
	switch(answer){
		case 1:
			printf("No. Please try again.");
		break;
		case 2:
			printf("Wrong. Try once more.");
		break;
		case 3:
			printf("Don't give up!");
		break;
		case 4:
			printf("No. Keep trying.");
		break;
		default:
			assert("Something got wrong. Please reboot");
	}
	printf("\n\n");
}

void calculateResult(int w){
	float percentage;
	
	percentage = ((float)w)/QUESTIONS * 100.0;
	
	if(percentage <= 25.0){
		printf("Congratulations, you are ready to go to the next level\n\n");
	}
	else
		printf("Please ask your teacher for extra help\n\n");
}

int selectDifficultyLevel(void){
	int d = 0;
	
	while(d != 1 && d != 2 && d != 3){
		printf("Enter difficulty level between 1, 2 and 3: ");
		scanf("%d", &d);
	}
	return d;
}

void selectOperation(void){
	int wrongSelection = 1;
	
	while(wrongSelection == 1){
		printf("Enter 1 for questions on addition, 2 for questions on subtraction, 3 for multiplication, 4 for a mix of them: ");
		scanf("%d", &selectEntry);
		if(selectEntry > 4)
			printf("Wrong selection.\n");
		else
			wrongSelection = 0;
	}
	
	operation = selectEntry;

}

int checkResult(int result){
	switch(operation){
		case 1:
			if(a+b == result)
				return 1;
		break;
		case 2:
			if(a-b == result)
				return 1;
		break;
		case 3:
			if(a*b == result)
				return 1;
		break;
		default:
			assert("Error 002. Wrong operation when checking");
	}
	
	return 0;
}
