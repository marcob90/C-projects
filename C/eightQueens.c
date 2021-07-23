#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHESSBOARD_SIZE 8
#define FULL_SQUARE '*'

void printChessboard(int[][CHESSBOARD_SIZE], const int);
int placeQueens(int[][CHESSBOARD_SIZE], const int);
void resetChessboard(int[][CHESSBOARD_SIZE], const int);

int main(){
	int placedEightQueens = 0; //this flag is false till the program finds a solution of the problem
	int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE];
	
	srand(time(NULL)); //random initialization
	
	while(!placedEightQueens){ //run till a solution is found
		resetChessboard(chessboard, CHESSBOARD_SIZE); //fill chessboard with 0s
		
		placedEightQueens = placeQueens(chessboard, CHESSBOARD_SIZE); //return 1 if 8 queens were placed on the chessboard, 0 otherwise

		printChessboard(chessboard, CHESSBOARD_SIZE);
	}
	
	return 0;
}

int placeQueens(int cB[][CHESSBOARD_SIZE], const int size){
	void updateValues(int[][CHESSBOARD_SIZE], int[][CHESSBOARD_SIZE], const int);
	void updateChessboard(const int, const int, int[][CHESSBOARD_SIZE], const int);
	int findMinimumValue(int[][CHESSBOARD_SIZE], const int);
	
	//matrix that contains information about queens, empty spaces or forbidden spaces
	int squareValue[CHESSBOARD_SIZE][CHESSBOARD_SIZE] = {{0}}; 
	int minimum;
	int queen;
	int i, j;
	
	//try to place eight queens
	for(queen = 1; queen <= CHESSBOARD_SIZE; queen++){
		updateValues(cB, squareValue, CHESSBOARD_SIZE); //update information at every cycle
		
		//find squares that will cover less empty spaces after placing a queen
		minimum = findMinimumValue(squareValue, size);
		
		//if no queen can be placed return 0
		if(minimum == FULL_SQUARE) 
			return 0;
		
		//place queen in one of those squares otherwise
		i = rand() % size;
		j = rand() % size;
		
		while(squareValue[i][j] != minimum){
			i = rand() % size;
			j = rand() % size;
		}
		
		//update the board after placing a queen
		updateChessboard(i, j, cB, size);
	}
	
	//if the function reaches this point, 8 queens were placed successfully
	return 1;
}

void updateChessboard(const int x, const int y, int cB[][CHESSBOARD_SIZE], const int size){
	int i, j;
	
	//row
	i = x;
	
	for(j = 0; j < size; j++){
		cB[i][j] = FULL_SQUARE;
	}
	
	//column
	j = y;
	
	for(i = 0; i < size; i++){
		cB[i][j] = FULL_SQUARE;
	}
	
	//diagonals
	i = x;
	j = y;
	
	while(i >= 0 && i < size && j >= 0 && j < size){
		cB[i][j] = FULL_SQUARE;
		i++;
		j++;
	}
	
	i = x;
	j = y;
	while(i >= 0 && i < size && j >= 0 && j < size){
		cB[i][j] = FULL_SQUARE;
		i--;
		j++;
	}
	
	i = x;
	j = y;
	while(i >= 0 && i < size && j >= 0 && j < size){
		cB[i][j] = FULL_SQUARE;
		i++;
		j--;
	}
	
	i = x;
	j = y;
	while(i >= 0 && i < size && j >= 0 && j < size){
		cB[i][j] = FULL_SQUARE;
		i--;
		j--;
	}
	
	cB[x][y] = 'Q';
}

int countEmptySpaces(const int x, const int y, int c[][CHESSBOARD_SIZE], const int size){
	int i, j;
	int emptySpaces = 0;
	
	//count empty spaces on row
	i = x;
	
	for(j = 0; j < size; j++){
		if(c[i][j] == 0){
			emptySpaces++;
		}
	}
	
	//count empty spaces on column
	j = y;
	
	for(i = 0; i < size; i++){
		if(c[i][j] == 0){
			emptySpaces++;
		}
	}
	
	//count empty spaces on diagonals
	i = x;
	j = y;
	
	while(i >= 0 && i < size && j >= 0 && j < size){
		if(c[i][j] == 0){
			emptySpaces++;
		}
		i++;
		j++;
	}
	
	i = x;
	j = y;
	while(i >= 0 && i < size && j >= 0 && j < size){
		if(c[i][j] == 0){
			emptySpaces++;
		}
		i--;
		j++;
	}
	
	i = x;
	j = y;
	while(i >= 0 && i < size && j >= 0 && j < size){
		if(c[i][j] == 0){
			emptySpaces++;
		}
		i++;
		j--;
	}
	
	i = x;
	j = y;
	while(i >= 0 && i < size && j >= 0 && j < size){
		if(c[i][j] == 0){
			emptySpaces++;
		}
		i--;
		j--;
	}
	
	if(c[x][y] == 0)
		emptySpaces -= 5; //the initial square has to be counted just once
		
	return emptySpaces; 
}

void updateValues(int cB[][CHESSBOARD_SIZE], int sV[][CHESSBOARD_SIZE], const int size){
	int countEmptySpaces(const int, const int, int[][CHESSBOARD_SIZE], const int);
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			//for every element, update the board of values, defining if a square is a queen, forbidden or just empty. If empty, count empty spaces. 
			sV[i][j] = (cB[i][j] == FULL_SQUARE || cB[i][j] == 'Q') ? FULL_SQUARE : countEmptySpaces(i, j, cB, size); 
		}
	}
}

int findMinimumValue(int sV[][CHESSBOARD_SIZE], const int size){
	int i, j;
	int min = '*';
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			if(sV[i][j] < min){
				min = sV[i][j];
			}
		}
	}
	
	return min;
}

void resetChessboard(int board[][CHESSBOARD_SIZE], const int size){
	int i, j;
	
	for(i = 0; i < size; i++)
			for(j = 0; j < size; j++)
				board[i][j] = 0;
			
}

void printChessboard(int c[][CHESSBOARD_SIZE], const int size){
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%4c", c[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
}
