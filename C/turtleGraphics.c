#include <stdio.h>
#include <assert.h>
#define SIZE 50
#define COMMAND_SIZE 5

void interpreteCommand(const char[]);
void turnRight(void);
void turnLeft(void);
void printMatrix(void);
void moveTurtle(const char[]);
void draw(int);


enum PenStatus{
	DOWN,
	UP
};

enum PenStatus penStatus = UP;
int row = 0;
int column = 0;
int movingOnRow = 1;
int rowsAreIncreasing = 1;
int columnsAreIncreasing = 1;
int square[SIZE][SIZE] = {{0}};

int main(){
	char command[COMMAND_SIZE];
	
	while(command[0] != '9'){
		printf("%s\t  %s\n\n", "Command", "Meaning");
		printf("1\t  Pen Down\n2\t  Pen Up\n3\t  Turn Right\n4\t  Turn Left\n5,10\t  Move forward 10 spaces(or a number other then 10)\n6\t  Print map\n9\t  End of data\n\n");
		printf("Enter command: ");
		scanf("%4s", command);
		interpreteCommand(command);
	}
	
	return 0;
}

void interpreteCommand(const char c[]){
	switch(c[0]){
		case '1':
			penStatus = DOWN;
		break;
		case '2':
			penStatus = UP;
		break;
		case '3':
			turnRight();
		break;
		case '4':
			turnLeft();
		break;
		case '5':
			moveTurtle(c);
		break;
		case '6':
			printMatrix();
		break;
		default:
			printf("Command is not valid\n");
	}
}

void turnRight(void){
	if(movingOnRow){
		movingOnRow = 0;
		rowsAreIncreasing = columnsAreIncreasing ? 1 : 0;
	}
	else{
		movingOnRow = 1;
		columnsAreIncreasing = rowsAreIncreasing ? 0 : 1;
	}
}

void turnLeft(void){
	if(movingOnRow){
		movingOnRow = 0;
		rowsAreIncreasing = columnsAreIncreasing ? 0 : 1;
	}
	else{
		movingOnRow = 1;
		columnsAreIncreasing = rowsAreIncreasing ? 1 : 0;
	}
}

void printMatrix(){
	int i, j;
	
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			printf("%2d", square[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void moveTurtle(const char c[]){
	int movement = 0;

	movement = c[3] == '\0' ? ( c[2] - '0' ) : ( (int)( c[2] - '0' ) * 10 + (int)( c[3] - '0' ) );
	
	printf("%d\n", movement);
	
	if(movingOnRow && columnsAreIncreasing){
		column += movement;
	}
	else if(movingOnRow && !columnsAreIncreasing){
		column -= movement;
	}
	else if(!movingOnRow && rowsAreIncreasing){
		row += movement;
	}
	else if(!movingOnRow && !rowsAreIncreasing){
		row -= movement;
	}

	assert(column < SIZE && column >= 0 && row < SIZE && row >= 0);
		
	if(penStatus == DOWN){
		draw(movement);
	}
}

void draw(int move){
	int i;
	
	if(movingOnRow && columnsAreIncreasing){
		for(i = column; i >= column - move; i--)
			square[row][i] = 1;
	}
	else if(movingOnRow && !columnsAreIncreasing){
		for(i = column; i <= column + move; i++)
			square[row][i] = 1;
	}
	else if(!movingOnRow && rowsAreIncreasing){
		for(i = row; i >= row - move; i--)
			square[i][column] = 1;
	}
	else if(!movingOnRow && !rowsAreIncreasing){
		for(i = row; i <= row + move; i++)
			square[i][column] = 1;
	}
}
