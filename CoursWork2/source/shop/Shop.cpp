#include "shop/Shop.h"
#include "customers/CustomersDB.h"
#include "animals/PetDB.h"
#include "animals/Pet.h"
#include "customers/Customer.h"

Shop::Shop(PetDb& petDb, CustomersDb& customersDB)
{
	locaUsagePetDb = &petDb;
	locaUsageCustomersDB = &customersDB;
}

void Shop::startShoping(int CustomerId)
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

		Pet* petToBuy;
		Customer* currentCusomer;
		float availableBalance;
		float petPrice;
		float finalPetPrice;

		switch (shopingOption)
		{
		case 0:
			isShoping = false;
			break;
		case 1:
			locaUsagePetDb->ShowAllPets();
			break;
		case 2:
			petToBuy = locaUsagePetDb->FindPetByID();
			currentCusomer = locaUsageCustomersDB->findCustomerById(CustomerId);

			availableBalance = currentCusomer->getBalance();
			petPrice = petToBuy->getpetPriceWithoutDiscount();
			finalPetPrice = currentCusomer->getPriceWithDiscount(petPrice);

			if (availableBalance < finalPetPrice) cout << "You Don't Have enought Money";
			else
			{
				currentCusomer->reduceBalance(finalPetPrice);
				petToBuy->BuyPet(CustomerId);
			}
			break;

		case 3:
			petToBuy = locaUsagePetDb->FindPetByID();
			currentCusomer = locaUsageCustomersDB->findCustomerById(CustomerId);

			if (availableBalance < finalPetPrice) cout << "This Pet Is Not Available For Rent";
			else
			{
				currentCusomer->reduceBalance(finalPetPrice);
				petToBuy->BuyPet(CustomerId);
			}
			break;
		}

		if (shopingOption == 0) continue; // avoid doble cout from shop and main
		cout << "press Enter To Continue...";
		cin.ignore();  // flush  
		cin.get();

	}
}
