#pragma once


class Account
{
public:
	Account();
	void setBalance();
	float getBalance();
	void showBalance();
	void reduceBalance(float reduceAmmount);
private:
	float balance;
};