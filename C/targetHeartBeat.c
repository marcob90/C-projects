#include <stdio.h>

int main() {
	int birthDay;
	int birthMonth;
	int birthYear; 
	int currentDay;
	int currentMonth;
	int currentYear;
	int age;
	int maxRate;
	
	printf("Enter your birth year: ");
	scanf("%d", &birthYear);
	printf("Enter your birth month: ");
	scanf("%d", &birthMonth);
	printf("Enter your birth day: ");
	scanf("%d", &birthDay);
	printf("Enter current year: ");
	scanf("%d", &currentYear);
	printf("Enter current month: ");
	scanf("%d", &currentMonth);
	printf("Enter current day: ");
	scanf("%d", &currentDay);
	
	if(birthMonth > currentMonth)
		age = currentYear - birthYear - 1;
	else if(birthMonth < currentMonth)
		age = currentYear - birthYear;
	else if(birthMonth == currentMonth){
		if(birthDay > currentDay)
			age = currentYear - birthYear - 1;
		else if(birthDay <= currentDay)
			age = currentYear - birthYear;
	}
	maxRate = 220-age;
	printf("Your are %d years old\n", age);
	printf("\nThe maximum heart beat rate per minute for your age should be %.2f\n", (float)maxRate);
	printf("\nYour target heart beat rate per minute should be between %.2f and %.2f\n", 0.5f * maxRate, 0.85f * maxRate);
	
	return 0;
}
