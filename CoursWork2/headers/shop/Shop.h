#pragma once
#include <iostream>
using namespace std;

//forward Declaration
class PetDb;
class CustomersDb;
class Customer;
class Pet;

class Shop
{
public:
	Shop(PetDb& petDb, CustomersDb& customersDB);
	void startShoping(Customer& currentCustomer);
	void BuyPet(Customer& currentCustomer);
	void RendPet(Customer& currentCustomer);

private:
	PetDb* locaUsagePetDb;
	CustomersDb* locaUsageCustomersDB;
	Pet* CurrentPet;
};