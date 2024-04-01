#include "pets/Cat.h"

int Cat::catAmountOfPetsInStock = 0;
int Cat::petPopularity = 0;

//if DB pre-created in main.cpp
Cat::Cat(string name, string petDescription, float petPrice) : 
	Pet(name, petDescription, petPrice)
{
	catAmountOfPetsInStock++;
}

//Constructor if pet is added through console
Cat::Cat()
{
	catAmountOfPetsInStock++;
}

//ATTENTION
void Cat::aksForFood()
{
	cout << getPetName() << ": is hungry and asks for a fish" << endl;
}

void Cat::aksForAttention()
{
	cout << getPetName() << ": is bored and asks for a play with a ball" << endl;
}

//BUY OVERRIDE
void Cat::BuyPet(int customerId)
{
	catAmountOfPetsInStock--;
	petPopularity++;
	Pet::BuyPet(customerId);
}

//RENT HANDLER
void Cat::RentPet(int customerId)
{
	catAmountOfPetsInStock--;
	petPopularity++;
	Pet::RentPet(customerId);
}

bool Cat::isRentPeriodFinished()
{
	//call base class 
	bool isRentFinished = Pet::isRentPeriodFinished();
	if (isRentFinished)
	{
		catAmountOfPetsInStock++;
		petPopularity--;
	}
	return isRentFinished;
}

//Type
string Cat::getPetType()
{
	return petType;
}

 
 
