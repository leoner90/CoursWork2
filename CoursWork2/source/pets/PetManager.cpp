#include "pets/PetManager.h"
#include "pets/PetDB.h"
#include "customers/CustomersDB.h"
#include <chrono>
#include <ctime>   
#include <iomanip>

PetManager::PetManager(PetDb& petDb, CustomersDb& customersDB)
{
	localPetManager = &petDb;
	localCustomersDb = &customersDB;
}

//PET INIT
void PetManager::PetManagerInit(int currentCustomerId)
{

	currentCustomerPetList = localPetManager->GetCustomerPets(currentCustomerId); // get ALL CUSTOMER PETS
	localCustomerId = currentCustomerId; // CUSTOMER ID , saved for local usage

	bool isPetManagerActive = true;
	msgForUserActive = false;
	int petManagerOption;
	enum SelectionOptions {Exit, AllPetCheck, ChangePetName, FeedPets, PlayWithPets, ShowStatistic};

	//init
	while (isPetManagerActive)
	{
		system("cls");
		cout << "you can check, Feed and Play With a pets" << endl;
		cout << "1 - Check All Your  Pets" << endl;
		cout << "2 - Change Pet Name" << endl;
		cout << "3 - Feed All Your Pets" << endl;
		cout << "4 - Play With All Your Pets" << endl;
		cout << "5 - Show How Many Pet Owned And On Trial" << endl;
		cout << "0 - Exit Pet Manager" << endl;
		cin >> petManagerOption;

		switch (petManagerOption)
		{
		case Exit:
			isPetManagerActive = false;
			currentCustomerPetList.clear();
			break;
		case AllPetCheck:
			PetsStatusUpdate();
			askForAttention();
			showCustomerPets();
			break;
		case ChangePetName:
			changePetName();
			break;

		case FeedPets:
			feedPets();
			break;

		case PlayWithPets:
			playWithPets();
			break;

		case ShowStatistic:
			ShowPetStatistic();
			break;
		}

		if (petManagerOption == 0) continue; // avoid doble cout from shop and main
		cout << "press Enter To Continue...";
		cin.ignore();  // flush  
		cin.get();
	}
}

//SHOW ALL CUSTOMER PETS , IF IN RENT SHOW TIME LEFT
void PetManager::showCustomerPets()
{
	system("cls");
	cout << endl << "LIST OF YOU PETS: " << endl;

	for (auto pet : currentCustomerPetList)
	{
		cout
			<< "Pet ID: " << pet->getPetId() << endl
			<< "Type:  " << pet->getPetType() << endl
			<< "Name: " << pet->getPetName() << endl
			<< "Description:  " << pet->getPetDescription() << endl;

		//REMAINING ENERGY LEVEL
		cout << "ENERGY LEVELS:" << endl;
		cout 
			<< setw(9) << "Satiety" 
			<< setw(9) << "Energy" 
			<< setw(9) <<  "Mood" 
			<< setw(20) << "Friendliness" << endl;
		cout 
			<< setw(9) << pet->getHungerLvl() << "%" 
			<< setw(9) << pet->getEnergyLvl() << "%"  
			<< setw(9) << pet->getMoodIndex() << "%"  
			<< setw(15) << pet->getFriendlinessIndex() << "%" << endl;
 
		//TRIAL
		if (pet->getRentStatus())
		{
			long rentTimeLeft = pet->rentTimeLeft();
			cout << "Trial Ends in : ";
			rentTimeLeft > 0 ? cout << rentTimeLeft << " seconds" : cout << "Expired";
		}

		cout << endl << "----------------------" << endl << endl;
	}
}

//IF ENERGY LEVEL ARE LESS THEN 50% ASK FOR FOOD OR ATTENTION
void PetManager::askForAttention() 
{
	for (auto pet : currentCustomerPetList)
	{
		if (pet->getFriendlinessIndex() < 50 || pet->getHungerLvl() < 50)
		{
			pet->aksForFood();
			msgForUserActive = true;
		}

		if (pet->getMoodIndex() < 50 || pet->getFriendlinessIndex() < 50)
		{
			pet->aksForAttention();
			msgForUserActive = true;
		}
	}

	if (msgForUserActive)
	{
		msgForUserActive = false;
		cout << "press Enter To Continue...";
		cin.ignore();  // flush  
		cin.get();
	}
}
//IF ENERGY LEVEL ARE LESS THEN 50% ASK FOR FOOD OR ATTENTION
//IF RENT TIME IS FINISHED RETURN TO PETS TO THE SHOP
void PetManager::PetsStatusUpdate()
{
	system("cls");
	long currentTime = (long)std::time(nullptr);
	for (auto pet : currentCustomerPetList)
	{
		long lastFeedingTime = pet->getlastFeedingTime();
		long lastPlayTime = pet->getlastPlayTime() ;
		float threeMin = 180.f; // 3 min

		//prev status - new status( based on  time passed)  = % 

		float currentHungerLvlinPercent = 100.f - (100.f * ((currentTime - lastFeedingTime) / threeMin));  // after 3 min = 0% satiety
		float currentHappinessLvlinPercent = 100.f - (100.f * ((currentTime - lastPlayTime) / threeMin)); // after 3 min = 0% happynes
 
		if (currentHungerLvlinPercent < 0) currentHungerLvlinPercent = 0; // if negative set to 0 
		pet->setHungerLvl((float)currentHungerLvlinPercent);
		pet->setEnergyLvl((float)currentHungerLvlinPercent);

		if (currentHappinessLvlinPercent < 0) currentHappinessLvlinPercent = 0;  // if negative set to 0
		pet->setFriendlinessIndex((float)currentHappinessLvlinPercent);
		pet->setMoodIndex((float)currentHappinessLvlinPercent);

		//IF ON TRIAL PERIOD
	}
	checkTrial();
}

//CHANGE PET NAME (ONLY IF OWNER)
void PetManager::changePetName()
{
	localPetManager->FindPetByID(false)->setPetName(localCustomerId);
}


//FEED ALL PETS
void PetManager::feedPets()
{
	for (auto pet : currentCustomerPetList)
	{
		pet->setEnergyLvl(100.f);
		pet->setHungerLvl(100.f);
		pet->updateLastFeedTime();
	}
	cout << "All Pets Are Fed";
}

//PLAY WITH ALL PETS
void PetManager::playWithPets()
{
	for (auto pet : currentCustomerPetList)
	{
		pet->setFriendlinessIndex(100.f);
		pet->setMoodIndex(100.f);
		pet->updateLastPlayTime();
	}
	cout << "All Pets Are Happy Now";
}


//Show How Many Pets Owned Or on Trial
void PetManager::ShowPetStatistic()
{
	cout << "TOTAL PETS OWNED: " << localCustomersDb->findCustomerById(localCustomerId)->getNumberOfPetsOwned() << endl;
	cout << "TOTAL PETS ON TRIAL: " << localCustomersDb->findCustomerById(localCustomerId)->getNumberOfPetsOnTrial() << endl;
}

void PetManager::checkTrial()
{
	//bug avoiding , as vector erase raise an error if i continue loop in the same loop
	bool recursive = false; 
	for (auto pet : currentCustomerPetList)
	{
		bool rentStatus = false;
		//cheack pet status , if rent is expired reset owner id and is pet in rent condition
		rentStatus = pet->isRentPeriodFinished();
		//removes pet from local Storage

		if (rentStatus)
		{
			currentCustomerPetList.erase(find(currentCustomerPetList.begin(), currentCustomerPetList.end(), pet));
			localCustomersDb->findCustomerById(localCustomerId)->setNumberOfPetsOnTrial(-1);
			msgForUserActive = true;
			recursive = true; // erasing from array BUG
			break;
		}
	}
	if (recursive) checkTrial();
}
