#include "customers/ElderyCustomer.h"

ElderyCustomer::ElderyCustomer(string inputLogin, string inputPassword, int inputAge, bool isAdmin) :
	Customer(inputLogin, inputPassword, inputAge, isAdmin)
{
	discountInPercent = 0.5f; // percentage
}

float ElderyCustomer::getPriceWithDiscount(float initPrice)
{
	float finalPrice = initPrice - (initPrice * discountInPercent); // () just for visability
	return finalPrice;
}

float ElderyCustomer::getDiscount()
{
	return discountInPercent;
}
