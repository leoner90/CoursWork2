#include "pets/Dog.h"

int Dog::dogAmountOfPetsInStock = 0;
int Dog::petPopularity = 0;

//if DB pre-created in main.cpp
Dog::Dog(string name, string petDescription, float petPrice) :
	Pet(name, petDescription, petPrice)
{
	dogAmountOfPetsInStock++;
}

//Constructor if pet is added through console
Dog::Dog()
{
	dogAmountOfPetsInStock++;
}

//ATTENTION
void Dog::aksForFood()
{
	cout << getPetName() << ": is hungry and asks for a bone" << endl;
}

void Dog::aksForAttention()
{
	cout << getPetName() << ": is bored and wants to run after a stick" << endl;
}

//BUY OVERRIDE
void Dog::BuyPet(int customerId)
{
	dogAmountOfPetsInStock--;
	petPopularity++;
	Pet::BuyPet(customerId);
}

//RENT HANDLER
void Dog::RentPet(int customerId)
{
	dogAmountOfPetsInStock--;
	petPopularity++;
	Pet::RentPet(customerId);
}

bool Dog::isRentPeriodFinished()
{
	bool isRentFinished = Pet::isRentPeriodFinished();
	if (isRentFinished)
	{
		dogAmountOfPetsInStock++;
		petPopularity--;
	}
	return isRentFinished;
}

//Type
string Dog::getPetType()
{
	return petType;
}