#include "pets/Fox.h"

int Fox::foxAmountOfPetsInStock;
int Fox::petPopularity = 0;

//if DB pre-created in main.cpp
Fox::Fox(string name, string petDescription, float petPrice) :
	Pet(name, petDescription, petPrice)
{
	foxAmountOfPetsInStock++;
}

//Constructor if pet is added through console
Fox::Fox()
{
	foxAmountOfPetsInStock++;
}

//ATTENTION
void Fox::aksForFood()
{
	cout << getPetName() << ": is hungry and asks for a chicken" << endl;
}

void Fox::aksForAttention()
{
	cout << getPetName() << ": is bored and wants to run after a car" << endl;
}

//BUY OVERRIDE
void Fox::BuyPet(int customerId)
{
	foxAmountOfPetsInStock--;
	petPopularity++;
	Pet::BuyPet(customerId);
}

//RENT HANDLER
void Fox::RentPet(int customerId)
{
	foxAmountOfPetsInStock--;
	petPopularity++;
	Pet::RentPet(customerId);
}

bool Fox::isRentPeriodFinished()
{
	bool isRentFinished =   Pet::isRentPeriodFinished();
	if (isRentFinished)
	{
		foxAmountOfPetsInStock++;
		petPopularity--;
	} 
	return isRentFinished;
}

//PET TYPE
string Fox::getPetType()
{
	return petType;
}