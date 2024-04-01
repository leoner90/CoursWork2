#pragma once
#include <vector>
#include <iostream>
#include "pets/Pet.h"

using namespace std;

class PetDb
{
public:
	std::vector<Pet*> allPets;
 
	void ShowAllPets();
	void AddNewPet();
	void AddNewPet(int type, string name, string petDescription, float petPrice);
	void DeletePet();
	Pet* FindPetByID(bool checkOwner = true);
	vector<Pet*> GetCustomerPets(int CustomerId);
private:
};