#pragma once
#include "customers\Customer.h"

class YoungCustomer : public Customer
{
public:
	YoungCustomer(string inputLogin, string inputPassword, int inputAge, bool isAdmin);
	float getPriceWithDiscount(float initPrice) override;
	float getDiscount() override;
	
private:
	float discountInPercent;
};