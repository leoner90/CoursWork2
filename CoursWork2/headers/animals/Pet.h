#pragma once
#include <iostream>
using namespace std;


//************ Abstract Class ************
class Pet
{
public:
	Pet(string name, string petDescription, float petPrice);
	Pet();

	//~Pet();
	
	// POLYMORF asking for food or attention.
	virtual void aksForFood() {};
	virtual void aksForAttention() {};

	void BuyPet(int customerId);
	void RentPet(int customerId);
	bool isRentPeriodFinished();

	//getters
	float getMoodIndex();
	float getFriendlinessIndex();
	float getEnergyLvl();
	float getHungerLvl();
	float getpetPriceWithoutDiscount();
	int getPetId();
	int getOwnerID();
	string getPetName();
	string getPetDescription();
 
	virtual string getPetType();

	//setters
	void setMoodIndex(float newMoodIndex);
	void setFriendlinessIndex(float newFriendlinessIndex);
	void setEnergyLvl(float newEnergyLvl);
	void setHungerLvl(float newHungerLvl);

private:

	string petType;

	//pet ID auto increment
	static int idIncrementer;
	int petID;

	string petName;
	string description; // what the pet does(a description)

	float moodIndex, friendlinessIndex, energyLvl, hungerLvl; // not static changes only when customer buys a pet

	float petPriceWithoutDiscount;

	//ownership statuses
	bool isInRent;
	bool hasOwner;
	int ownerId;
	
	bool freeTrial, purchasing;
	long timeOfpurchase, lastFeeding;
};