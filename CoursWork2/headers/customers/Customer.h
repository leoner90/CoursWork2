#pragma once
#include <iostream>
#include "Account.h"

using namespace std;

//************ Abstract Class ************

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
	//setters
	void setCustomerAddress();

	bool isCustomerAdmin();
	
private:
	int customerID;
	int CustomerAge;
	bool isAdmin;
	string login;
	string password;
	string CustomerName;
	string address;
	
	virtual void applyDiscount(int price) ;
	int numberOfPetsOwned, numberOfPetsOnTrial; // It should store the number of pets each customer has used as a free trial,
	float debtForPets; // the amount to be paid if the pet is not a free trial(a customer may buy few virtual pets at once).

	//pet ID auto increment
	static int idIncrementer;
	
 
	
};
 
 
 