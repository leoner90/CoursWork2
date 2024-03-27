#include "animals/Fox.h"

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

void Fox::aksForFood()
{

}

void Fox::aksForAttention()
{
}

string Fox::getPetType()
{
	return petType;
}


 