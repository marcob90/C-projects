#include <stdio.h>
#include <math.h>
#define SENTINEL -99999
#define SIZE 1000
#define READ 10
#define WRITE 11
#define WRITENEWLINE 12
#define READSTRING 13
#define WRITESTRING 14
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define REMAINDER 34
#define POWER 35
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void printDump(void);
void inputString(float *);
void printString(float *);

float memory[SIZE] = {0.0f};
float accumulator = 0.0f;
int instructionCounter = 0;
int operationCode = 0;
int operand = 0;
int instructionRegister = 0;

int main(){
	
	printf("*** Welcome to Simpletron! ***\n"
			"*** Please enter your program one instruction ***\n"
			"*** (or data word) at a time. I will type the ***\n"
			"*** location number and a question mark (?). ***\n"
			"*** You then type the word for that location. ***\n"
			"*** Type the sentinel -99999 to stop entering ***\n"
			"*** your program. ***\n\n");
			
	while(instructionCounter < SIZE){ //commands input
		
		do{
			printf("%03d ? ", instructionCounter);
			scanf("%f", &memory[instructionCounter]);
			if(abs((int)memory[instructionCounter]) > 9999 && (int)memory[instructionCounter] != SENTINEL){
				printf("User input invalid. Please try again.\n");
			}
    	}while(abs((int)memory[instructionCounter]) > 9999 && (int)memory[instructionCounter] != SENTINEL);
		
		if((int)memory[ instructionCounter ] == SENTINEL)
			break;
			
		instructionCounter++;
	}
	
	printf("\n*** Program loading completed ***\n*** Program execution begins ***\n");
	instructionCounter = 0;
	
	while(instructionCounter < SIZE){  //program execution
		instructionRegister = memory[ instructionCounter ];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
	
		switch(operationCode){
			case READ: 
				do{
					scanf("%f", &memory[operand]);
					if(abs(memory[operand]) > 9999){
						printf("User input invalid. Please try again.\n");
					}
				}while(abs(memory[operand]) > 9999);
				instructionCounter++;
			break;
			
			case WRITE: 
				printf( "%.2f", memory[ operand ] );
				instructionCounter++;
			break;
			
			case WRITENEWLINE: 
				printf("\n");
				instructionCounter++;
			break;
			
			case READSTRING:
				inputString(&memory[ operand ]);
				instructionCounter++;
			break;
			
			case WRITESTRING:
				printString(&memory[ operand ]);
				instructionCounter++;
			break;
			
			case LOAD: 
				accumulator = memory[ operand ];
				instructionCounter++;
			break;
			
			case STORE: 
				memory[ operand ] = accumulator;
				instructionCounter++;
			break;
			
			case ADD: 
				accumulator += memory[ operand ];
				if(abs(accumulator) > 9999){
					printf("*** Accumulator overflow ***\n"
						   "*** Simpletron execution abnormally terminated ***\n");
					accumulator = 9999.0f;
					printDump();
					instructionCounter = SIZE;
				}
				else
					instructionCounter++;
			break;
			
			case SUBTRACT: 
				accumulator -= memory[ operand ];
				if(abs(accumulator) > 9999){
					printf("*** Accumulator overflow ***\n"
						   "*** Simpletron execution abnormally terminated ***\n");
					accumulator = 9999.0f;
					printDump();
					instructionCounter = SIZE;
				}
				else
					instructionCounter++;
			break;
			
			case DIVIDE: 
				if(memory[ operand ] == 0){
					printf("*** Attempt to divide by zero ***\n"
						   "*** Simpletron execution abnormally terminated ***\n");
					printDump();
					instructionCounter = SIZE;
				}
				else{
					accumulator /= memory[ operand ];
					instructionCounter++;
				}
			break;
			
			case MULTIPLY: 
				accumulator *= memory[ operand ];
				if(abs(accumulator) > 9999){
					printf("*** Accumulator overflow ***\n"
						   "*** Simpletron execution abnormally terminated ***\n");
					accumulator = 9999.0f;
					printDump();
					instructionCounter = SIZE;
				}
				else
					instructionCounter++;
			break;
			
			case REMAINDER: 
				if(memory[ operand ] == 0){
					printf("*** Attempt to divide by zero ***\n"
						   "*** Simpletron execution abnormally terminated ***\n");
					printDump();
					instructionCounter = SIZE;
				}
				else{
					accumulator = (int)(accumulator) % (int)(memory[ operand ]);
					instructionCounter++;
				}
			break;
			
			case POWER: 
				accumulator = pow(accumulator, memory[ operand ]);
				if(abs(accumulator) > 9999){
					printf("*** Accumulator overflow ***\n"
						   "*** Simpletron execution abnormally terminated ***\n");
					accumulator = 9999.0f;
					printDump();
					instructionCounter = SIZE;
				}
				else
					instructionCounter++;
			break;
			
			case BRANCH: 
				instructionCounter = operand;
			break;
			
			case BRANCHNEG: 
				if(accumulator < 0)
					instructionCounter = operand;	
			break;
			
			case BRANCHZERO: 
				if(accumulator == 0)
					instructionCounter = operand;
			break;
			
			case HALT: 
				printf("\n*** Simpletron execution terminated ***\n\n");
				printDump();
				instructionCounter = SIZE;
			break;
			
			default:
				printf("*** Invalid operation code detected ***\n"
					   "*** Simpletron execution abnormally terminated ***\n");
				instructionCounter = SIZE;
				printDump();
		}
	}
	
	return 0;
}

void inputString(float *memPtr){
	char string[50];
	int counter;
	int i;
	
	scanf("%s", string);
	for(counter = 0; string[counter] != '\0'; counter++){
		//empty body
	}
	*memPtr = (counter << 8) | string[0];
	
	for(i = 1; 2 * i <= counter; i++){
		
		2 * i == counter ? ( *(memPtr + i) = ( *( string + 2 * i - 1 ) << 8 ) ) : ( *(memPtr + i) = ( *( string + 2 * i - 1) << 8 ) | ( *( string + 2 * i ) ) );

	}
}

void printString(float *memPtr){
	int counter;
	int size;
	
	size = (int)*memPtr >> 8;
	
	printf("%c", ((int)*memPtr & 0xff));
	
	for(counter = 1; counter <= size / 2; counter++){
		if(size % 2 == 0 && counter == size / 2)
			printf("%c", ((int)*(memPtr + counter) >> 8));
		else
			printf("%c%c", ((int)*(memPtr + counter) >> 8), ((int)*(memPtr + counter) & 0xff));
	}
	
}

void printDump(void){
	int i;
	
	printf("REGISTERS:\naccumulator\t\t");
	
	printf("%+1.2f\ninstructionCounter\t%6d\n"
		   "instructionRegister\t%1s%05x\noperationCode\t\t%6d\noperand\t\t\t%6d\n\n", 
			accumulator, instructionCounter, "+", instructionRegister, operationCode, operand);
	printf("MEMORY:\n");
	
	for(i = 0; i < 10; i++){
		printf("\t%5d", i);
	}
	
	for(i = 0; i < SIZE; i++){
		if(i % 10 == 0)
			printf("\n  %3d\t", i);
		
		printf("%s%04x\t", memory[ i ] < 0 ? "-" : "+", abs(memory[ i ]));
	}

}
