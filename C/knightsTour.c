#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHESSBOARD_SIZE 8
#define MOVES 8
#define TOURS 1000

void printChessboard(int[][CHESSBOARD_SIZE], int);
void run(int[][CHESSBOARD_SIZE], int);
int findNextMove(int, int, int[][CHESSBOARD_SIZE], int);
void modifyAccessibility(int a[][CHESSBOARD_SIZE], int, int, int);
int checkIfTourIsClosed(const int, const int, int board[][CHESSBOARD_SIZE], const int);

const int horizontal[MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
const int vertical[MOVES] = {-1, -2, -2, -1, 1, 2, 2, 1};
int closedTours = 0;

int main(){
	int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE] = {{0}};
	int count = 1;
	
	srand(time(NULL));
	while(count <= TOURS){
		run(chessboard, CHESSBOARD_SIZE);
		printChessboard(chessboard, CHESSBOARD_SIZE);
		count++;
	}	
	
	printf("Number of closed tours: %d", closedTours);
	
	return 0;
}

void run(int c[][CHESSBOARD_SIZE], int size){
	int accessibility[CHESSBOARD_SIZE][CHESSBOARD_SIZE] = {{2, 3, 4, 4, 4, 4, 3, 2},
							   							   {3, 4, 6, 6, 6, 6, 4, 3},
							   						       {4, 6, 8, 8, 8, 8, 6, 4},
													   	   {4, 6, 8, 8, 8, 8, 6, 4},
													   	   {4, 6, 8, 8, 8, 8, 6, 4},
													   	   {4, 6, 8, 8, 8, 8, 6, 4},
												       	   {3, 4, 6, 6, 6, 6, 4, 3},
													   	   {2, 3, 4, 4, 4, 4, 3, 2}};
							   	      
	int currentRow, currentColumn;
	int moveNumber = 0;
	int move;
	
	currentRow = rand() % 2 * (size - 1);
	currentColumn = rand() % 2 * (size - 1);
	
	for(move = 1; move <= size*size && moveNumber != -1; move++){ // cycle all moves. If there's not a legal move, exit cycle
		c[currentRow][currentColumn] = move;
		modifyAccessibility(accessibility, currentRow, currentColumn, size);
		
		moveNumber = findNextMove(currentRow, currentColumn, accessibility, size);
		
		if(moveNumber != -1 && move != size*size){
			currentRow += vertical[moveNumber];  
			currentColumn += horizontal[moveNumber];
		}
   }
   
   if(move == size*size + 1){
   		if(checkIfTourIsClosed(currentRow, currentColumn, c, size))
   			closedTours++;
   	}
	
}

int findNextMove(int row, int column, int a[][CHESSBOARD_SIZE], int s){
	int min = 10;
	int access1, access2;
	int nextRow;
	int nextColumn;
	int nextMove = -1;
	int n;
	
	for(n = 0; n < MOVES; n++){ 
		nextRow = row + vertical[n];  
		nextColumn = column + horizontal[n];
		
		if(nextRow < 0 || nextRow >= s || nextColumn < 0 || nextColumn >= s)
			continue;
		
		if(a[nextRow][nextColumn] < min){
			min = a[nextRow][nextColumn];
			nextMove = n;
		}
		else if(a[nextRow][nextColumn] == min){
			access1 = findSmallestAccess(nextRow, nextColumn, a, s);
			access2 = findSmallestAccess(row + vertical[nextMove], column + horizontal[nextMove], a, s);
			nextMove = access1 < access2 ? n : nextMove;
		}
	}
	
	return nextMove;
}

int findSmallestAccess(int row, int column, int acc[][CHESSBOARD_SIZE], int s){
	int nextRow;
	int nextColumn;
	int n;
	int min = 10;
	
	for(n = 0; n < MOVES; n++){ 
		nextRow = row + vertical[n];  
		nextColumn = column + horizontal[n];
		
		if(nextRow < 0 || nextRow >= s || nextColumn < 0 || nextColumn >= s)
			continue;
		
		if(acc[nextRow][nextColumn] < min){
			min = acc[nextRow][nextColumn];
		}
	}
		
	return min;
}

void modifyAccessibility(int a[][CHESSBOARD_SIZE], int row, int column, int s){
	int n;
	int nextRow, nextColumn;
	
	a[row][column] = 10;
	
	for(n = 0; n < MOVES; n++){ 
		nextRow = row + vertical[n];  
		nextColumn = column + horizontal[n];
		
		if(nextRow < 0 || nextRow >= s || nextColumn < 0 || nextColumn >= s)
			continue;
		
		else if(a[nextRow][nextColumn] != 10)
			a[nextRow][nextColumn]--;
	}
	
}

int checkIfTourIsClosed(const int row, const int column, int board[][CHESSBOARD_SIZE], const int size){
	int n;
	int nextRow, nextColumn;
	
	for(n = 0; n < MOVES; n++){ 
		nextRow = row + vertical[n];  
		nextColumn = column + horizontal[n];
		
		if(nextRow < 0 || nextRow >= size || nextColumn < 0 || nextColumn >= size)
			continue;
		
		if(board[nextRow][nextColumn] == 1){
			return 1;
		}
	}
	
	return 0;
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


