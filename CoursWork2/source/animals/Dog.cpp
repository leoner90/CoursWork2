#include "animals/Dog.h"

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

void Dog::aksForFood()
{

}

void Dog::aksForAttention()
{
}

string Dog::getPetType()
{
	return petType;
}
 

 