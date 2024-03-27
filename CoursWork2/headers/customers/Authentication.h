#pragma once
#include <iostream>

//Forward Declaration
class CustomersDb;

using namespace std;


class Authentication 
{
public:
	Authentication(CustomersDb& customersDb);
	int loginCustomer();
	int registerNewCustomer();
	bool validation();

private:
	string login;
	string password, rPassword;
	int age;
	CustomersDb* localAccessToCustomersDb;
};