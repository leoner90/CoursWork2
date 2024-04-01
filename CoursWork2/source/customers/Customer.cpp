#include "customers/Customer.h"
#include "string"

 //Static ID
int Customer::idIncrementer = 0;

//************* Constructor
Customer::Customer(string inputLogin, string inputPassword, int inputAge, bool adminRights)
{
	idIncrementer++;
	customerID = idIncrementer;

	login = inputLogin;
	password = inputPassword;
	CustomerAge = inputAge;

	//total pets owned
	numberOfPetsOwned = 0;
	numberOfPetsOnTrial = 0; // It should store the number of pets each customer has used as a free trial,

	isAdmin = adminRights;
	//if not admin ask all info
	if (!adminRights)
	{
		cout << "Type in your name please" << endl;
		cin.ignore();  // flush  
		getline(std::cin, CustomerName);

		cout << "Type in your address" << endl;
		cin.ignore();  // flush  
		getline(std::cin, address);

		setBalance();
	}
}


//************* GETERS
int Customer::getCustomerId()
{
	return customerID;
}

string Customer::getCustomerLogin()
{
	return login;
}

string Customer::getCustomerPassword()
{
	return password;
}

string Customer::getCustomerName()
{
	return CustomerName;
}

string Customer::getCustomerAddress()
{
	return address;
}

int Customer::getCustomerAge()
{
	return CustomerAge;
}

int Customer::getNumberOfPetsOwned()
{
	return numberOfPetsOwned;
}

int Customer::getNumberOfPetsOnTrial()
{
	return numberOfPetsOnTrial;
}

//************* Setters
void Customer::setCustomerAddress()
{
	 
	string newAddress;
	cout << "Type in your new address please" << endl;
	cin.ignore();  // flush  
	getline(std::cin, newAddress);
	address = newAddress;

	std::cout << "Your Address Changed successfully: " << endl;
}


//************* REST
bool Customer::isCustomerAdmin()
{
	return isAdmin;
}

void Customer::setNumberOfPetsOwned(int value)
{
	numberOfPetsOwned += value;
}

void Customer::setNumberOfPetsOnTrial(int value)
{
	numberOfPetsOnTrial += value;
}

