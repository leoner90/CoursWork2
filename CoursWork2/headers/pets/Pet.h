#pragma once
#include <iostream>
using namespace std;

class Pet
{
public:
	Pet(string name, string petDescription, float petPrice);
	Pet();
	//~Pet();
	
	// POLYMORF asking for food or attention.
	virtual void aksForFood() {};
	virtual void aksForAttention() {};
	virtual void setPopulation() {};
	virtual void BuyPet(int customerId);
	virtual void RentPet(int customerId);
	virtual bool isRentPeriodFinished();


	//getters
	float getMoodIndex();
	float getFriendlinessIndex();
	float getEnergyLvl();
	float getHungerLvl();
	float getpetPriceWithoutDiscount();
	long getlastFeedingTime();
	long getlastPlayTime();
	int getPetId();
	int getOwnerID();
	bool isOwnerSet();
	bool getRentStatus();
	long rentTimeLeft();
	string getPetName();
	string getPetDescription();
 
	virtual string getPetType();

	//setters
	void setMoodIndex(long newMoodIndex);
	void setFriendlinessIndex(long newFriendlinessIndex);
	void setEnergyLvl(long newEnergyLvl);
	void setHungerLvl(long newHungerLvl);
	void setPetName(int customerId);
	void updateLastFeedTime();
	void updateLastPlayTime();
private:

	string petType;

	//pet ID auto increment
	static int idIncrementer;
	int petID;

	//info
	string petName;
	string description; // what the pet does(a description)

	//energy levels
	float moodIndex, friendlinessIndex, energyLvl, hungerLvl; // not static changes only when customer buys a pet

	//Discount Price
	float petPriceWithoutDiscount;

	//ownership statuses
	bool isInRent;
	bool hasOwner;
	int ownerId;
	
	bool freeTrial, purchasing;
	long timeOfpurchase, lastFeedingTime, lastPlayTime;
};