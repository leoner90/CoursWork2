#include <iostream>
#include "customers/CustomersDB.h"
#include "customers/Customer.h"
#include "pets/PetDB.h"
#include "customers/Authentication.h"
#include "shop/Shop.h"
#include "pets/PetManager.h"
#include <ctime>   

using namespace std;

//Main Objects
PetDb* petDb = new PetDb();
CustomersDb* customersDB = new CustomersDb();
Authentication authentication(*customersDB);
Shop* shop = new Shop(*petDb, *customersDB);
PetManager petManager(*petDb, *customersDB);

int main()
{
	bool isProgrammRunning = true;
	int currentCustomerId = -1;
	bool isLoggedIn = false;

	//PETS DB PRE - CREATION - CATS( type 0)
	petDb->AddNewPet(0,"Bob", "Little buddy", 200);
	petDb->AddNewPet(0, "Fluffy", "Prepare your vacuum cleaner , he is everywhere", 300);
	petDb->AddNewPet(0, "Sleepy", "He will oversleep everyone, even you", 900);

	//PETS DB PRE - CREATION - DOGS (type 1)
	petDb->AddNewPet(1, "Cooper", "Graceful, mysterious, and independent.", 200);
	petDb->AddNewPet(1, "Sadie", "Loyal, affectionate, and endlessly enthusiastic companions.", 300);
	petDb->AddNewPet(1, "Luna", "Playful, loyal, and eager to please, dogs are the ultimate furry friends, always ready for adventure.", 900);

	//PETS DB PRE - CREATION - FOXES ( type2)
	petDb->AddNewPet(2, "Rusty", "Agile hunters of the wild, with sleek coats and cunning eyes, embodying both grace and intelligence.", 200);
	petDb->AddNewPet(2, "Willow", "Adaptable and elusive, foxes roam the forests with stealth, their fiery fur blending seamlessly with the autumn hues of their habitat.", 300);
	petDb->AddNewPet(2, "Finn", "Known for their sly demeanor and playful antics, foxes captivate with their charming curiosity and swift movements, embodying the untamed spirit of the wilderness.", 900);
 
	//creating admin
	customersDB->AddNewCustomer(29, "admin", "admin", true);
 
	while (isProgrammRunning)
	{
		//************** Authorization
		if (!isLoggedIn)
		{
			int authorizationType;
			enum AuthorizationTypes {NONE, LOGIN, REG };
			cout << "Log In or Register , 1 - log in , 2 - reg" << endl;
			
			cin >> authorizationType;

			switch (authorizationType)
			{
			case LOGIN:
				currentCustomerId = authentication.loginCustomer();
				if (currentCustomerId != -1) isLoggedIn = true;
				break;

			case REG:
				currentCustomerId = authentication.registerNewCustomer();
				if (currentCustomerId != -1) isLoggedIn = true; // auto login after registration
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
			//IF LOGGED IN AS ADMIN
			int selection;
			system("cls");

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
				enum regularcustomerOptions { LogOut, ShowBalance, Setbalance, SetAddress, PetManager, Shoping };
				Customer* currentCustomer = customersDB->findCustomerById(currentCustomerId);
				cout << "As A CUSTOMER You Have Ability To  ADD / CHECK BALANCE and ADDRESS , check you pets, feed pets , shopping" << endl;
				cout << "1 - Check Balance" << endl;
				cout << "2 - Add Balance" << endl;
				cout << "3 - Change Address" << endl;
				cout << "4 - Open Pet Manager" << endl;
				cout << "5 - Shoping" << endl;
				cout << "0 - Log out" << endl;
				cin >> selection;

				switch (selection)
				{
				case LogOut:
					isLoggedIn = false;
					break;
				case ShowBalance:
					currentCustomer->showBalance();
					break;
				case Setbalance:
					currentCustomer->setBalance();
					break;
				case SetAddress:
					currentCustomer->setCustomerAddress();
					break;
				case PetManager:
					petManager.PetManagerInit(currentCustomerId);
			 
					break;
				case Shoping:
					shop->startShoping(*currentCustomer);
					 
				}
				cout << "press Enter To Continue...";
				cin.ignore();  // flush  
				cin.get();
				system("cls");
			}
		}
	}
}