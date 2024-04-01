#pragma once
#include "pets/PetDB.h"

//Forward Declaration
class PetDb;
class Pet;
class CustomersDb;

class PetManager
{
public:
	PetManager(PetDb& petDb, CustomersDb& customersDB);
	//~PetManager();
	void PetManagerInit(int currentCustomerId);
	//void CheckCustomerPets();
	void showCustomerPets();
	void askForAttention();

	void feedPets();
	void playWithPets();

	void PetsStatusUpdate(); //ask for attention //ask for food 
	void changePetName(); //change Name
	void ShowPetStatistic();

	void checkTrial();
private:
	PetDb* localPetManager;
 
	int localCustomerId;
	std::vector<Pet*> currentCustomerPetList;
	CustomersDb* localCustomersDb;
	bool msgForUserActive;
};