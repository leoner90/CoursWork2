#pragma once
#include "customers/Customer.h"
#include <iostream>
#include <vector>

using namespace std;

class CustomersDb 
{
public:
	//authorisation
	void AddNewCustomer(int age, string login, string password, bool isAdmin = false);

	int FindCustomerId(string login, string password);
	bool DoesCustomerExists(string login);
	Customer* findCustomerById(int id);

	//if admin
	void ShowAllCustomers();
	void DeleteCustomer();

private:
	std::vector<Customer*> allCustomers;
};