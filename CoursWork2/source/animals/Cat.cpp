#include "animals/Cat.h"

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

void Cat::aksForFood()
{

}

void Cat::aksForAttention()
{
}

string Cat::getPetType()
{
	
	return petType;
}

 
 
