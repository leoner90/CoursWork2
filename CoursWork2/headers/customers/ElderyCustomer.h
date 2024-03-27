#pragma once
#include "customers\Customer.h"

class ElderyCustomer : public Customer
{
public:
	ElderyCustomer(string inputLogin, string inputPassword, int inputAge, bool isAdmin);
	float getPriceWithDiscount(float initPrice) override;
	float getDiscount() override;
private:
	float discountInPercent;
};

 