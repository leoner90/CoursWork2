#include "customers/RegularCustomer.h"

RegularCustomer::RegularCustomer(string inputLogin, string inputPassword, int inputAge, bool isAdmin) :
	Customer(inputLogin, inputPassword, inputAge, isAdmin)
{
	discountInPercent = 0.f; // percentage
}

float RegularCustomer::getPriceWithDiscount(float initPrice)
{
	float finalPrice = initPrice - (initPrice * discountInPercent); // () just for visability
	return finalPrice;
}

float RegularCustomer::getDiscount()
{
	return discountInPercent;
}