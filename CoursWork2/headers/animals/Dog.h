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

	//getters
	string getPetType() override;

	//numbers
	static int dogAmountOfPetsInStock;
	static int petPopularity; // how was bought 
private:

	//pets in stock
	const string petType = "DOG";

};

 