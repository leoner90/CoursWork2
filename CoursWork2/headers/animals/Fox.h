#pragma once
#include "Pet.h"
#include <iostream>

using namespace std;

class Fox : public Pet
{
public:
	Fox();
	Fox(string name, string petDescription, float petPrice);

	void aksForFood() override;
	void aksForAttention() override;

	//getters
	string getPetType() override;

	//numbers
	static int foxAmountOfPetsInStock;
	static int petPopularity; // how many people have bought specific pets STATIC

private:
	const string petType = "FOX";
	//pets in stock

};

