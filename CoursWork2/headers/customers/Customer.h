#pragma once
#include <iostream>
#include "Account.h"

using namespace std;

class Customer : public Account
{
public:
	Customer(string inputLogin, string inputPassword, int inputAge, bool adminRights);

	//getters
	int getCustomerId();
	string getCustomerLogin();
	string getCustomerPassword();
	string getCustomerName();
	string getCustomerAddress();
	int getCustomerAge();
	virtual float getPriceWithDiscount(float initPrice) { return 0;};
	virtual float getDiscount() { return 0;};
	int getNumberOfPetsOwned();
	int getNumberOfPetsOnTrial();

	//setters
	void setCustomerAddress();
	bool isCustomerAdmin();
	void setNumberOfPetsOwned(int value);
	void setNumberOfPetsOnTrial(int value);
	
private:
	int customerID;
	int CustomerAge;
	bool isAdmin;
	string login;
	string password;
	string CustomerName;
	string address;

	int numberOfPetsOwned, numberOfPetsOnTrial; // It should store the number of pets each customer has used as a free trial,

	//ID auto increment
	static int idIncrementer;
};