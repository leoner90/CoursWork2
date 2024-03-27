#include <iostream>
#include "customers/CustomersDB.h"
#include "customers/Customer.h"
#include "animals/PetDB.h"
#include "customers/Authentication.h"
#include "shop/Shop.h"
 

using namespace std;

PetDb* petDb = new PetDb();
CustomersDb* customersDB = new CustomersDb();
Authentication authentication(*customersDB);
Shop* shop = new Shop(*petDb, *customersDB);

int main()
{
	//PETS DB PRE - CREATION - CATS( type 0)

	petDb->AddNewPet(0,"Bob", "Little buddy", 200);
	petDb->AddNewPet(0, "Fluffy", "Prepare your vacuum cleaner , he is everywhere", 300);
	petDb->AddNewPet(0, "Sleepy", "He will oversleep everyone, even you", 900);

	//PETS DB PRE - CREATION - DOGS (type 1)
	petDb->AddNewPet(1, "Bob", "Little buddy", 200);
	petDb->AddNewPet(1, "Fluffy", "Prepare your vacuum cleaner , he is everywhere", 300);
	petDb->AddNewPet(1, "Sleepy", "He will oversleep everyone, even you", 900);

	//PETS DB PRE - CREATION - FOXES ( type2)
	petDb->AddNewPet(2, "Bob", "Little buddy", 200);
	petDb->AddNewPet(2, "Fluffy", "Prepare your vacuum cleaner , he is everywhere", 300);
	petDb->AddNewPet(2, "Sleepy", "He will oversleep everyone, even you", 900);


	bool isProgrammRunning = true;
	int currentCustomerId = -1;
	bool isLoggedIn = false;

	//creating admin
	customersDB->AddNewCustomer(29, "admin", "admin", true);
 
	while (isProgrammRunning)
	{
		//************** Authorization
		if (!isLoggedIn)
		{
			int authorizationType;
			enum AuthorizationTypes { LOGIN, REG };
			cout << "Log In or Register , 0 - log in , 1 - reg" << endl;
			
			cin >> authorizationType;

			switch (authorizationType)
			{
			case LOGIN:
				currentCustomerId = authentication.loginCustomer();
				if (currentCustomerId != -1) isLoggedIn = true;
				break;

			case REG:
				authentication.registerNewCustomer();
				break;

			default:
				system("cls");
				cout << "UNSUPPORTED OPERATION (press enter to repeat)" << endl;
				cin.ignore();  // flush  
				cin.get();
				break;
			}
		}
		else 
		{
	
			int selection;
			system("cls");

		 

			//IF CASE IS ADMIN
			if (customersDB->findCustomerById(currentCustomerId)->isCustomerAdmin())
			{
				//admin account(add customers , delete customers,add pet , delete pet, ),  << endl;
				cout << "As Admin You Have Ability To Add, Delete and Check all Cusomters and Pets" << endl;
				cout << "1 - ADD Customer" << endl;
				cout << "2 - Delete Customer By ID" << endl;
				cout << "3 - Check All Cusomers" << endl;
				cout << "4 - ADD Pet" << endl;
				cout << "5 - Delete Pet By ID" << endl;
				cout << "6 - Check All Pets" << endl;
				cout << "0 - Log out" << endl;
				cin >> selection;

				switch (selection)
				{
				case 0:
					isLoggedIn = false;
					break;
				case 1:
					authentication.registerNewCustomer();
					break;
				case 2:
					customersDB->DeleteCustomer();
					break;
				case 3:
					customersDB->ShowAllCustomers();
					break;
				case 4:
					petDb->AddNewPet();
					break;
				case 5:
					petDb->DeletePet();
					break;
				case 6:
					petDb->ShowAllPets();
					break;
				}
				cout << "press Enter To Continue...";
				cin.ignore();  // flush  
				cin.get();
			}
			//IF JUST MORTAL CUSTOMER
			else 
			{
				//account(CHANGE BALANCE , check balance , change address, check pets) FEED PET"
				//SHOP (buy rent pet) 
						//admin account(add customers , delete customers,add pet , delete pet, ),  << endl;
				cout << "As A CUSTOMER You Have Ability To  ADD / CHECK BALANCE and ADDRESS , check you pets, feed pets , shopping" << endl;
				cout << "1 - Check Balance" << endl;
				cout << "2 - Add Balance" << endl;
				cout << "3 - Change Address" << endl;
				cout << "4 - Check Your Pets" << endl;
				cout << "5 - Feed Your Pets" << endl;
				cout << "6 - Shoping" << endl;
				cout << "0 - Log out" << endl;
				cin >> selection;

				switch (selection)
				{
				case 0:
					isLoggedIn = false;
					break;
				case 1:
					customersDB->findCustomerById(currentCustomerId)->showBalance();
					break;
				case 2:
					customersDB->findCustomerById(currentCustomerId)->setBalance();
					break;
				case 3:
					customersDB->findCustomerById(currentCustomerId)->setCustomerAddress();
					break;
				case 4:
					petDb->ShowCustomerPets(currentCustomerId);
					break;
				case 5:
					 
					break;

				case 6:
					shop->startShoping(currentCustomerId);
					 
				}
				cout << "press Enter To Continue...";
				cin.ignore();  // flush  
				cin.get();
				system("cls");
			}
		 
			
		}
	
	}

	
 
}


 



//this pet is not available for rent
//check you can't rent and buy and see pet which allready owned
//usage of abstract classes

//PET HENDLER
//ask for attention
//ask for food
//change Name
//Play
//Feed
//Check Levels



//check reqremnet by task
//check code + comments
