#include <iostream>

#include "SavingsAccount.h"

using namespace std;

int main()
{
	double interest;
	cout << "Account1\n";
	SavingsAccount Account1( 2000.0 );
	cout << endl;
	
	cout << "Account2\n";
	SavingsAccount Account2( 3000.0 );
	cout << endl;
	
	cout << "Account1\n";
	interest = Account1.calculateMonthlyInterest();
	cout << "Interest: " << interest << endl;
	Account1.print();
	cout << endl;
	
	cout << "Account2\n";
	interest = Account2.calculateMonthlyInterest();
	cout << "Interest: " << interest << endl;
	Account2.print();
	cout << endl;
	
	cout << "**********Set interest rate 4%**********\n\n";
	SavingsAccount::modifyInterestRate( 0.04 );
	
	cout << "Account1\n";
	interest = Account1.calculateMonthlyInterest();
	cout << "Interest: " << interest << endl;
	Account1.print();
	cout << endl;
	
	cout << "Account2\n";
	interest = Account2.calculateMonthlyInterest();
	cout << "Interest: " << interest << endl;
	Account2.print();
	cout << endl;
}
