#include <stdio.h>

void hanoi(int disks, int sPeg, int fPeg, int hPeg);
int main() {
	int numberOfDisks = 3;
	int startPeg = 1;
	int finalPeg = 3;
	int holdingPeg = 2;
	
	printf("Solution with %d disks:\n\n", numberOfDisks);
	hanoi(numberOfDisks, startPeg, finalPeg, holdingPeg);
	return 0;
}

void hanoi(int disks, int sPeg, int fPeg, int hPeg){
	if(disks > 1){
		hanoi(disks - 1, sPeg, hPeg, fPeg);
		printf("%d -> %d\n", sPeg, fPeg);
		hanoi(disks - 1, hPeg, fPeg, sPeg);
	}
	else if(disks == 1)
		printf("%d -> %d\n", sPeg, fPeg);
	else
	printf("Insert some disks in the sourse peg");
}
