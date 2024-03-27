#include "animals/Pet.h"
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
	moodIndex = friendlinessIndex = energyLvl = hungerLvl = 100;
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

	//set all energy to the max 100 %
	moodIndex = friendlinessIndex = energyLvl = hungerLvl = 100;
}


void Pet::BuyPet(int customerId)
{
	time_t time = std::time(nullptr);
	hasOwner = true;
	ownerId = customerId;
	lastFeeding = time;
}

void Pet::RentPet(int customerId)
{
	hasOwner = true;
	isInRent = true;
	ownerId = customerId;
}

bool Pet::isRentPeriodFinished()
{
	float trialPeriod = 60000 * 5; // 5 min
	time_t time = std::time(nullptr);
	if (timeOfpurchase + trialPeriod < time) return true;
	else return false;
}

//GETTERS
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

int Pet::getPetId()
{
	return petID;
}

int Pet::getOwnerID()
{
	if (!hasOwner) return false;
	else return ownerId;
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
void Pet::setMoodIndex(float newMoodIndex)
{
	moodIndex = newMoodIndex;
}

void Pet::setFriendlinessIndex(float newFriendlinessIndex)
{
	friendlinessIndex = newFriendlinessIndex;
}

void Pet::setEnergyLvl(float newEnergyLvl)
{
	energyLvl = newEnergyLvl;
}

void Pet::setHungerLvl(float newHungerLvl)
{
	hungerLvl = newHungerLvl;
}
