#pragma once
#include "customers\Customer.h"

class RegularCustomer : public Customer
{
public:
	RegularCustomer(string inputLogin, string inputPassword, int inputAge, bool isAdmin);
	float getPriceWithDiscount(float initPrice) override;
	float getDiscount() override;

private:
	float discountInPercent;
};