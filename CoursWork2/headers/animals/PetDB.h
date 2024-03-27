#pragma once
#include <vector>
#include <iostream>
#include "animals/Pet.h"
#include "animals/Cat.h"
#include "animals/Dog.h"
#include "animals/Fox.h"

 

//Forward Declaration
class Dog;
class Fox;
class Bear;

using namespace std;


class PetDb
{
public:
	std::vector<Pet*> allPets;
 
	PetDb();
	void ShowAllPets();
	void AddNewPet();
	void AddNewPet(int type, string name, string petDescription, float petPrice);
	void DeletePet();
	Pet* FindPetByID();
	void ShowCustomerPets(int CustomerId);
private:
	

};




