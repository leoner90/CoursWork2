#include "shop/Shop.h"
#include "customers/CustomersDB.h"
#include "pets/PetDB.h"
#include "pets/Pet.h"
#include "customers/Customer.h"

//Constructor
Shop::Shop(PetDb& petDb, CustomersDb& customersDB)
{
	locaUsagePetDb = &petDb;
	locaUsageCustomersDB = &customersDB;
}

//shop init
void Shop::startShoping(Customer& currentCustomer)
{
	bool isShoping = true;
	int shopingOption;
	while (isShoping)
	{
		system("cls");
		cout << "you can checkk, buy and rent pets" << endl;
		cout << "1 - Check All Pets" << endl;
		cout << "2 - Buy Pet" << endl;
		cout << "3 - Rent Pet" << endl;
		cout << "0 - Exit Shop" << endl;
		cin >> shopingOption;

		switch (shopingOption)
		{
		case 0:
			isShoping = false;
			break;
		case 1:
			locaUsagePetDb->ShowAllPets();
			break;
		case 2:
			BuyPet(currentCustomer);
			break;
		case 3:
			RendPet(currentCustomer);
		}

		if (shopingOption == 0) continue; // avoid doble cout from shop and main
		cout << "press Enter To Continue...";
		cin.ignore();  // flush  
		cin.get();

	}
}

//BUY PET
void Shop::BuyPet(Customer& currentCustomer)
{

	float availableBalance = 0;
	float petPrice = 0;
	float finalPetPrice = 0;

	CurrentPet = locaUsagePetDb->FindPetByID();  // checks if this pet has owner
	if (CurrentPet == nullptr) return; // if return false

	availableBalance = currentCustomer.getBalance();
	petPrice = CurrentPet->getpetPriceWithoutDiscount();
	finalPetPrice = currentCustomer.getPriceWithDiscount(petPrice);

	if (availableBalance < finalPetPrice) cout << "You Don't Have enought Money";
	else
	{
		currentCustomer.reduceBalance(finalPetPrice);
		CurrentPet->BuyPet(currentCustomer.getCustomerId());
		currentCustomer.setNumberOfPetsOwned(1);

	}
}

//RENT PET
void Shop::RendPet(Customer& currentCustomer)
{
	CurrentPet = locaUsagePetDb->FindPetByID(); // checks if this pet has owner
	if (CurrentPet == nullptr) return;// if return false
	CurrentPet->RentPet(currentCustomer.getCustomerId());
	currentCustomer.setNumberOfPetsOnTrial(1);
}
