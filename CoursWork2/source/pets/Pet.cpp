#include "pets/Pet.h"
#include <ctime>   
#include "string"
int Pet::idIncrementer = 0;
 
//Constructor if DB pre-created in main.cpp
Pet::Pet(string name, string petDescription, float petPrice)
{
	petID = idIncrementer++;
	petName = name;
	description = petDescription;
	petPriceWithoutDiscount = petPrice;
	moodIndex = friendlinessIndex = energyLvl = hungerLvl = 100.f;
	hasOwner = false;
	isInRent = false;
	ownerId = -1;
}

//Constructor if pet is added through console
Pet::Pet()
{
	//id
	petID = idIncrementer++;

	//name
	std::cout << "Enter Pet Name: " << std::endl;
	std::cin >> petName;

	//Description
	std::cout << "Enter Pet Description: " << std::endl;
	cin.ignore();  // flush  
	getline(std::cin, description);

	//price
	std::cout << "Enter Pet Price: " << std::endl;
	std::cin >> petPriceWithoutDiscount;

	//set all energy to the max 100 % hungerLvl 100% = means not hungry at all
	moodIndex = friendlinessIndex = energyLvl = hungerLvl = 100;

	hasOwner = false;
	isInRent = false;
	ownerId = -1;
	std::cout << "Pet Added successfully: " << endl;
}

//BUY HANDLER
void Pet::BuyPet(int customerId)
{
	unsigned long time = (unsigned long)std::time(nullptr);
	hasOwner = true;
	ownerId = customerId;
	lastFeedingTime = time;
	lastPlayTime = time;
	std::cout << "You have successfully purchased a pet: " << endl;
}

//RENT HANDLER
void Pet::RentPet(int customerId)
{
	long time = (long)std::time(nullptr);
	timeOfpurchase = time;
	lastFeedingTime = time;
	lastPlayTime = time;

	isInRent = true;
	ownerId = customerId;
	std::cout << "You have successfully rented a pet: " << endl;
}

bool Pet::isRentPeriodFinished()
{
	float trialPeriod = 180.f; // 3 min
	long currentTime = (long)std::time(nullptr);
	if (timeOfpurchase - currentTime + trialPeriod < 0)
	{
		ownerId = -1;
		std::cout << "Yout Pet ID: " << petID <<  " rent time has expired - it is returned to the shop" << endl;
		isInRent = false;
		return true;
	}
	return false;
}

//GETTERS
long Pet::rentTimeLeft()
{
	float trialPeriod = 180.f; // 3 min
	long currentTime = (long)std::time(nullptr);
	return timeOfpurchase - currentTime + trialPeriod ;
}

float Pet::getMoodIndex()
{
	return moodIndex;
}

float Pet::getFriendlinessIndex()
{
	return friendlinessIndex;
}

float Pet::getEnergyLvl()
{
	return energyLvl;
}

float Pet::getHungerLvl()
{
	return hungerLvl;
}

float Pet::getpetPriceWithoutDiscount()
{
	return petPriceWithoutDiscount;
}

long Pet::getlastFeedingTime()
{
	return lastFeedingTime;
}

long Pet::getlastPlayTime()
{
	return lastPlayTime;
}

int Pet::getPetId()
{
	return petID;
}

int Pet::getOwnerID()
{
	return ownerId;
}

bool Pet::isOwnerSet()
{
	return hasOwner;
}

bool Pet::getRentStatus()
{
	return isInRent;
}

string Pet::getPetName()
{
	return petName;
}

string Pet::getPetDescription()
{
	return description;
}

string Pet::getPetType()
{
	return petType;
}

//SETTERS
void Pet::setMoodIndex(long newMoodIndex)
{
	moodIndex = newMoodIndex;
}

void Pet::setFriendlinessIndex(long newFriendlinessIndex)
{
	friendlinessIndex = newFriendlinessIndex;
}

void Pet::setEnergyLvl(long newEnergyLvl)
{
	energyLvl = newEnergyLvl;
}

void Pet::setHungerLvl(long newHungerLvl)
{
	hungerLvl = newHungerLvl;
}

void Pet::setPetName(int customerId)
{
	if (customerId == ownerId && hasOwner)
	{
		string newPetName;
		cout << "Enter New Pet Name" << endl;
		cin >> newPetName;

		petName = newPetName;
		std::cout << "Pet Name Changed successfully: " << endl;

	}
	else cout << "It's not your Pet or it dosen't exist or you are not the owner" << endl;
}

// FEED AND PLAY TIME SAVER
void Pet::updateLastFeedTime()
{
	lastFeedingTime = (unsigned long)std::time(nullptr);
}

void Pet::updateLastPlayTime()
{
	lastPlayTime = (unsigned long)std::time(nullptr);
}


 