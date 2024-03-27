#pragma once
#include <iostream>
using namespace std;

//forward Declaration
class PetDb;
class CustomersDb;

class Shop
{
public:
	Shop(PetDb& petDb, CustomersDb& customersDB);
	void startShoping(int CustomerId);
	void BuyPet();
	void RendPet();

private:
	PetDb* locaUsagePetDb;
	CustomersDb* locaUsageCustomersDB;

};