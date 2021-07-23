#include <stdio.h>
#include <math.h>
#define NUMBER_OF_DISKS 5

void moveDisk(int [], int [], int, int);

int main() {
	int sourcePeg[NUMBER_OF_DISKS];
	int auxPeg[NUMBER_OF_DISKS];
	int destPeg[NUMBER_OF_DISKS];
	int numberOfMoves;
	int count;
	int s = 1;
	int a = 2;
	int d = 3;
	
	printf("Solution with %d disks:\n\n", NUMBER_OF_DISKS);
	
	//initialization of pegs
	for(count = NUMBER_OF_DISKS - 1; count >= 0; count--){ 
		sourcePeg[count] = NUMBER_OF_DISKS-count;
		auxPeg[count] = 0;
		destPeg[count] = 0;
	}
	
	//if number of diks is even, swap destination peg with auxiliary peg
	if(NUMBER_OF_DISKS % 2 == 0){ 
		a = 3;
		d = 2;
	}
	
	for(numberOfMoves = 1; numberOfMoves <= (int)pow(2, NUMBER_OF_DISKS)-1; numberOfMoves++){
		if(numberOfMoves % 3 == 1){
			//movement between source and dest
			moveDisk(sourcePeg, destPeg, s, d);
		}
		else if(numberOfMoves % 3 == 2){
			//movement between source and aux
			moveDisk(sourcePeg, auxPeg, s, a);
		}
		else if(numberOfMoves % 3 == 0){
			//movement between dest and aux
			moveDisk(auxPeg, destPeg, a, d);
		}
	}

	return 0;
}

void moveDisk(int sPeg[], int fPeg[], int from, int to){
	int sTopDisk, fTopDisk, sCount, fCount;
	
	for(sCount = NUMBER_OF_DISKS-1; sCount >= 0; sCount--){
		if(sPeg[sCount] != 0){
			sTopDisk = sPeg[sCount];
			break;
		}
		else sTopDisk = 0;
	}
	
	for(fCount = NUMBER_OF_DISKS-1; fCount >= 0; fCount--){
		if(fPeg[fCount] != 0){
			fTopDisk = fPeg[fCount];
			break;
		}
		else 
			fTopDisk = 0;
	}
	
	if(fTopDisk == 0){
		sPeg[sCount] = 0;
		fPeg[0] = sTopDisk;
		printf("%d -> %d\n", from, to);
	}
	else if(sTopDisk == 0){
		fPeg[fCount] = 0;
		sPeg[0] = fTopDisk;
		printf("%d -> %d\n", to, from);
	}
	else if(sTopDisk < fTopDisk){
		sPeg[sCount] = 0;
		fPeg[fCount+1] = sTopDisk;
		printf("%d -> %d\n", from, to);
	}
	else{
		fPeg[fCount] = 0;
		sPeg[sCount+1] = fTopDisk;
		printf("%d -> %d\n", to, from);
	}
		
		
}
