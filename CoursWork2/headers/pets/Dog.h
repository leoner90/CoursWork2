#pragma once
#include "Pet.h"
#include <iostream>

using namespace std;

class Dog : public Pet
{
public:
	Dog();
	Dog(string name, string petDescription, float petPrice);
	
	void aksForFood() override;
	void aksForAttention() override;
	void BuyPet(int customerId) override;
	void RentPet(int customerId) override;
	bool isRentPeriodFinished() override;

	//getters
	string getPetType() override;

	//static numbers (public!!!)
	static int dogAmountOfPetsInStock;
	static int petPopularity; // how many was bought 

private:
	//pets in stock
	const string petType = "DOG";
};