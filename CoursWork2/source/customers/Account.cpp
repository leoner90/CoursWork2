#include "customers/Account.h"
#include <iostream>

using namespace std;

Account::Account()
{ 
	balance = 0; // safe guard
}

void Account::setBalance()
{
	float AddBalance = 0;
	cout << "Enter amount of money to put into your account" << endl;
	cin >> AddBalance;
	balance += AddBalance;
	std::cout << "You Balance Updated successfully: " << endl;
}

float Account::getBalance()
{
	return balance; 
}

void Account::showBalance()
{
	cout << "Your Balance is: " << balance << endl;
}

void Account::reduceBalance(float reduceAmmount)
{
	balance -= reduceAmmount;
}