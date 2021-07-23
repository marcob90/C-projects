#include <stdio.h>

int main() {
	int accountNumber;
	double beginningBalance;
	double totalCharges;
	double totalCredits;
	double creditLimit;
	double balance;
	
	printf("Enter the account number (%d to end): ", EOF);
	scanf("%d", &accountNumber);
	
	while(accountNumber != EOF){
		printf("Enter beginning balance: ");
		scanf("%lf", &beginningBalance);
		
		printf("Enter total charges: ");
		scanf("%lf", &totalCharges);
		
		printf("Enter total credits: ");
		scanf("%lf", &totalCredits);
		
		printf("Enter total limit: ");
		scanf("%lf", &creditLimit);
		
		balance = beginningBalance + totalCharges - totalCredits;
		
		if(balance > creditLimit){
			printf("Account:\t%d\nCredit limit:\t%.2lf\nBalance:\t%.2lf\nCredit Limit Exceeded\n", accountNumber, creditLimit, balance);
		}
		
		printf("\nEnter the account number (%d to end): ", EOF);
		scanf("%d", &accountNumber);
	}
	return 0;
}
