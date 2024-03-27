#include "customers/YoungCustomer.h"

YoungCustomer::YoungCustomer(string inputLogin, string inputPassword, int inputAge, bool isAdmin):
	Customer(inputLogin, inputPassword, inputAge, isAdmin)
{
	discountInPercent = 0.25f; // percentage
}

float YoungCustomer::getPriceWithDiscount(float initPrice)
{
	float finalPrice = initPrice - (initPrice  * discountInPercent); // () just for visability
	return finalPrice;
}

float YoungCustomer::getDiscount()
{
	return discountInPercent;
}
