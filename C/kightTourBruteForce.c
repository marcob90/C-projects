#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHESSBOARD_SIZE 8
#define MOVES 8
#define TOURS 1

void printChessboard(int[][CHESSBOARD_SIZE], int);
void resetChessboard(int[][CHESSBOARD_SIZE], int);
void run(int[][CHESSBOARD_SIZE], int);

const int horizontal[MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
const int vertical[MOVES] = {-1, -2, -2, -1, 1, 2, 2, 1};
int completeTours = 0;

int main(){
	int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE] = {{0}};
	int count = 1;
	
	srand(time(NULL));
	while(count <= TOURS){
		run(chessboard, CHESSBOARD_SIZE);
		printChessboard(chessboard, CHESSBOARD_SIZE);
		resetChessboard(chessboard, CHESSBOARD_SIZE);
		count++;
	}	
	
	printf("Number of complete tours: %d", completeTours);
	
	return 0;
}

void run(int c[][CHESSBOARD_SIZE], int size){
	int currentRow, currentColumn;
	int moveNumber;
	int move;
	int row, column;
	int legalMoves[CHESSBOARD_SIZE] = {10};
	int legalMove = 0;
	int newMove = 10;
	int i;
	
	currentRow = row = rand() % size;
	currentColumn = column = rand() % size;
	c[currentRow][currentColumn] = 1;
	
	for(move = 2; move <= size*size; move++){

		for(moveNumber = 0; moveNumber < size; moveNumber++){
			currentRow = row + vertical[moveNumber];  
			currentColumn = column + horizontal[moveNumber];
		
			if(currentRow >= 0 && currentRow < size && currentColumn >= 0 && currentColumn < size && c[currentRow][currentColumn] == 0){
				legalMoves[moveNumber] = moveNumber;
				legalMove = 1;
			}	
		}
		
		if(legalMove){
			while(newMove == 10){
				newMove = legalMoves[rand() % size];
			}
			row += vertical[newMove];  
			column += horizontal[newMove];
			c[row][column] = move;
			legalMove = 0;
			newMove = 10;
			for(i = 0; i < size; i++)
				legalMoves[i] = 10;
		}
		else
			break;
	}
   
   if(move == size*size + 1)
   		completeTours++;
}

void printChessboard(int c[][CHESSBOARD_SIZE], int size){
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%4d", c[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
}

void resetChessboard(int c[][CHESSBOARD_SIZE], int size){
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			c[i][j] = 0;
		}
	}
}
