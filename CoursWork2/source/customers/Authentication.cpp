#include "customers/Authentication.h"
#include "customers/CustomersDB.h"

Authentication::Authentication(CustomersDb& customersDb)
{
	localAccessToCustomersDb = &customersDb; // create local DB on CLASS INIT
}

//LOGIN
int Authentication::loginCustomer()
{
	system("cls");
	cout << "LOGIN" << endl;
	cout << "Enter Login" << endl;
	cin >> login;
	cout << endl << "Enter Password" << endl;
	cin >> password;

	int customerId = localAccessToCustomersDb->FindCustomerId(login, password);
	cout << customerId << endl;
	if (customerId == -1)
	{
		int tryAgain = 0;
		cout << "Incorrect Details, Type 1 - to try again , 0 to exit  " << endl;
		cin >> tryAgain;
		if(tryAgain) loginCustomer();
	} 
	return customerId; // if 0 return -1 eg. false
}

//REGISTRATION
int Authentication::registerNewCustomer()
{

	system("cls");
	cout << "REGISTRATION" << endl;
	cout << "Enter Login" << endl;
	cin >> login;

	cout << "Enter Password" << endl;
	cin >> password;

	cout << "Repeat Password" << endl;
	cin >> rPassword;

	cout << "Enter Age" << endl;
	cin >> age;

	if (validation())
	{
		 localAccessToCustomersDb->AddNewCustomer(age, login, password); 
		 int customerId = localAccessToCustomersDb->FindCustomerId(login, password);
		 return customerId;
	}
	else 
	{
		cout << "Please Enter to re-enter your details" << endl;
		cin.ignore();  // flush  
		cin.get();
		registerNewCustomer();
	}

	return -1;
}

//VALIDATION
bool Authentication::validation()
{
	bool isValid = true;

	//if this login allready exist
	if (localAccessToCustomersDb->DoesCustomerExists(login))
	{
		cout << "Sorry this login is taken" << endl;
		isValid = false;
	}

	if (password.length() < 4 || login.length() < 4)
	{
		cout << "Password or Login are too short , please enter more than 4 symbols" << endl;
		isValid = false;
	}

	if (password == "" || login == "")
	{
		cout << "Password Or login can not be empty" << endl;
		isValid = false;
	}


	if (password != rPassword)
	{
		cout << "Password does not match, try again" << endl;
		isValid = false;
	}
	return isValid;
}