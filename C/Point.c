#include <stdio.h>

struct Employee{
	int age;
	float salary;
	char name[30];
};

void myFunc(const struct Employee *employee){
}

int main(){
	struct Employee softwareDeveloper = {28, 70000.0f, "Michael Jackson"};
	
	printf("%d, %d\n", sizeof(softwareDeveloper), sizeof(&softwareDeveloper));
	
	myFunc(&softwareDeveloper);
	
	return 0;
}
