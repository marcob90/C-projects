#include <stdio.h>
#include <math.h>

double distance(double, double, double, double);
int main(){
	int x1 = 0.0;
	int y1 = 1.0;
	int x2 = 0.0;
	int y2 = 5.0;
	
	printf("The distance is %lf", distance(x1,y1,x2,y2));
	return 0;
}

double distance(double x1, double y1, double x2, double y2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
