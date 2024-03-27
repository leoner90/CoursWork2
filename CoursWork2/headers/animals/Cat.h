#pragma once
#include "Pet.h"
#include <iostream>

using namespace std;

class Cat : public Pet
{
public:
	Cat(string name, string petDescription, float petPrice);
	Cat();

	// POLYMORF asking for food or attention.
	void aksForFood() override;
	void aksForAttention() override;

	//getters
	string getPetType() override;

	//Numbers
	static int catAmountOfPetsInStock;
	static int petPopularity;  
private:

	//pets in stock
	const string petType = "CAT";

	
};


