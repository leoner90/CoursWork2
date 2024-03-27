#include "animals/PetDB.h"
#include "animals/Pet.h"

  
PetDb::PetDb()
{
}

void PetDb::ShowAllPets()
{
	system("cls");
	int petType;
	cout << "Select Pet Type to Show" << endl;
	cout << "0 - CAT" << endl;
	cout << "1 - DOG" << endl;
	cout << "2 - FOX" << endl;
	cout << "3 - ALL" << endl;

	cin >> petType;
	system("cls");
	for (auto pet : allPets)
	{
		if (petType == 0 && pet->getPetType() != "CAT") continue;
		if (petType == 1 && pet->getPetType() != "DOG") continue;
		if (petType == 2 && pet->getPetType() != "FOX") continue;

		cout
			<< endl
			<< "Pet ID: " << pet->getPetId() << endl
			<< "Type:  " << pet->getPetType() << endl
			<< "Name: " << pet->getPetName() << endl
			<< "Description:  " << pet->getPetDescription() << endl
			<< "Price: " << pet->getpetPriceWithoutDiscount() << endl
			<< endl << "----------------------" << endl;	 
	}
	
	if (petType == 0 || petType == 3)
	{
		cout << "TOTAL CATS AVAILABLE: " << Cat::catAmountOfPetsInStock << endl;
		cout << "TOTAL CATS WAS PURCHASED: " << Cat::petPopularity << endl;
	}

	if (petType == 1 || petType == 3)
	{
		cout << "TOTAL DOG AVAILABLE: " << Dog::dogAmountOfPetsInStock << endl;
		cout << "TOTAL DOG WAS PURCHASED: " << Dog::petPopularity << endl;
	}

	if (petType == 2 || petType == 3)
	{
		cout << "TOTAL FOX AVAILABLE: " << Fox::foxAmountOfPetsInStock << endl;
		cout << "TOTAL FOX WAS PURCHASED: " << Fox::petPopularity << endl;
	}
	


	
}

// if pet is added through console
void PetDb::AddNewPet()
{
	int type;
	cout << "What kind of pet it is?" << endl;
	cout << "0 - CAT" << endl;
	cout << "1 - Dog" << endl;
	cout << "2 - Fox" << endl;
	cin >> type;

	if (type == 0) allPets.push_back(new Cat());
	else if (type == 1) allPets.push_back(new Dog());
	else if (type == 2) allPets.push_back(new Fox());
}

//if DB pre-created in main.cpp
void PetDb::AddNewPet(int type, string name, string petDescription, float petPrice)
{
	if (type == 0) allPets.push_back(new Cat(name, petDescription, petPrice));
	else if (type == 1) allPets.push_back(new Dog(name, petDescription, petPrice));
	else if (type == 2) allPets.push_back(new Fox(name, petDescription, petPrice));
}

void PetDb::DeletePet()
{
	int PetIdToDelete;
	bool isDeleted = false;
	cout << "Enter Pet Id" << endl;
	cin >> PetIdToDelete;

	for (auto pet : allPets)
	{
		if (pet->getPetId() == PetIdToDelete)
		{
			allPets.erase(find(allPets.begin(), allPets.end(), pet));
			delete pet;
			cout << "Deleted Successfully" << endl;
			isDeleted = true;
			break;
		}
	}
	if(!isDeleted) cout << "Wrong ID" << endl;

}

Pet* PetDb::FindPetByID()
{
	int petId;
	bool isPetFound = false;
	cout << "Enter Pet ID to Buy" << endl;
	cin >> petId;

	for (auto pet : allPets)
	{
		if (pet->getPetId() == petId)
		{
			isPetFound = true;
 
			return pet;
			 
		}
	}

	if(!isPetFound) cout << "Sorry no pet with such ID" << endl;
}

void PetDb::ShowCustomerPets(int CustomerId)
{
	for (auto pet : allPets)
	{
		if (!pet->getOwnerID()) continue;
		if (pet->getOwnerID() == CustomerId)
		{
			cout
				<< endl
				<< "Pet ID: " << pet->getPetId() << endl
				<< "Type:  " << pet->getPetType() << endl
				<< "Name: " << pet->getPetName() << endl
				<< "Description:  " << pet->getPetDescription() << endl
				<< "Price: " << pet->getpetPriceWithoutDiscount() << endl
				<< endl << "----------------------" << endl;

		}
	}
}
