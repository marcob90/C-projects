#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHESSBOARD_SIZE 8
#define FULL_SQUARE '*'

void printChessboard(int[][CHESSBOARD_SIZE], const int);
void updateValues(int[][CHESSBOARD_SIZE], int[][CHESSBOARD_SIZE], const int);
int countEmptySpaces(const int, const int, int[][CHESSBOARD_SIZE], const int);
int placeQueen(int[][CHESSBOARD_SIZE], const int, int);
void updateChessboard(const int, const int, int[][CHESSBOARD_SIZE], const int);
int findMinimumValue(int[][CHESSBOARD_SIZE], const int);
void resetChessboard(int[][CHESSBOARD_SIZE], const int);

int main(){
	int queenNumber = 0; //count number of Queens placed on Chessboard
	int placedEightQueens = 0;
	int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE];
	
	srand(time(NULL));
	
	while(!placedEightQueens){
		resetChessboard(chessboard, CHESSBOARD_SIZE);
		
		placedEightQueens = placeQueen(chessboard, CHESSBOARD_SIZE, queenNumber);

		printChessboard(chessboard, CHESSBOARD_SIZE);
	}
	
	return 0;
}

int placeQueen(int cB[][CHESSBOARD_SIZE], const int size, int queen){
	int squareValue[CHESSBOARD_SIZE][CHESSBOARD_SIZE] = {{0}};
	int minimum;
	int i, j;
	
	//place eight queens
	
	updateValues(cB, squareValue, CHESSBOARD_SIZE);
	
	minimum = findMinimumValue(squareValue, size);
	
	if(minimum == FULL_SQUARE && queen == 8)  //return 1 if the progrma placed 8 queens successfully, return 0 otherwise
		return 1;
	else if(minimum == FULL_SQUARE && queen < 8)
		return 0;
	else{   
		i = rand() % size;
		j = rand() % size;
	
		while(squareValue[i][j] != minimum){
			i = rand() % size;
			j = rand() % size;
		}
		updateChessboard(i, j, cB, size);
		
		return placeQueen(cB, size, queen + 1);
	}	
	
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
	
	for(i = 0; i < size; i++){
			for(j = 0; j < size; j++){
				board[i][j] = 0;
			}
	}
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
