#include "customers/CustomersDB.h"


CustomersDb::CustomersDb()
{
}

void CustomersDb::AddNewCustomer(int age, string login, string password, bool isAdmin)
{
	if(age < 14) allCustomers.push_back(new YoungCustomer(login, password, age, isAdmin));
	else if (age > 70) allCustomers.push_back(new ElderyCustomer(login, password, age, isAdmin));
	else allCustomers.push_back(new RegularCustomer(login, password, age, isAdmin));
	
	//if not admin
	if(!isAdmin) cout << endl << "Account Created Successfully" << endl;
}

int CustomersDb::FindCustomerId(string login, string password)
{
	int customerId = -1;
	for (auto customer : allCustomers)
	{
		if (customer->getCustomerLogin() == login && customer->getCustomerPassword() == password)
		{
			customerId = customer->getCustomerId();
		}
	}
	return customerId;
}

bool CustomersDb::DoesCustomerExists(string login)
{
	int exists = false;
	for (auto customer : allCustomers)
	{
		if (customer->getCustomerLogin() == login)
		{
			exists = true;
		}
	}
	return exists;
}

 

Customer* CustomersDb::findCustomerById(int id)
{
 
	for (auto customer : allCustomers)
	{
		if (customer->getCustomerId() == id)
		{
			return customer;
		}
	}	
	return nullptr;
}

//ADMIN ONLY
void CustomersDb::ShowAllCustomers()
{
	system("cls");
	for (auto customer : allCustomers)
	{
		cout 
			<< endl 
			<< "CUSTOMER ID: " << customer->getCustomerId() << endl
			<< "Login: " << customer->getCustomerLogin() << endl
			<< "Name:  " << customer->getCustomerName() << endl
			<< "Address: " << customer->getCustomerAddress() << endl
			<< "Balance: " << customer->getBalance() << endl
			<< "Age: " << customer->getCustomerAge() << endl
			<< "Discount: " << customer->getDiscount() << endl
			<< endl << "----------------------";
	}
}

//ADMIN ONLY
void CustomersDb::DeleteCustomer()
{
	int customerIdToDelete;
	bool isDeleted = false;

	cout << "Enter Customer Id" << endl;
	cin >> customerIdToDelete;

	for (auto customer : allCustomers)
	{
		if (customer->getCustomerId() == customerIdToDelete)
		{
			allCustomers.erase(find(allCustomers.begin(), allCustomers.end(), customer));
			delete customer;
			isDeleted = true;
			cout << "Deleted Successfully" << endl;
			break;
		}
 
	}
	if(!isDeleted) cout << "Wrong ID" << endl;
}


 