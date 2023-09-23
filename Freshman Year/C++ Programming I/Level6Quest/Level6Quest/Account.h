#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include "Transaction.h"

class Account
{
public:
	Account();
	Account(int ID, std::string firstName, std::string lastName, float beginningBalance);
	static int lastID;
	void addTransaction();
	void addTransaction(Date date, std::string description, float amount);
	float getCurrentBalance();
	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	float getBeginningBalance() const;
	std::vector<Transaction*> getTransactions() const;
	void print() const;
	void sort();
private:
	int ID;
	std::string firstName;
	std::string lastName;
	float beginningBalance;
	std::vector <Transaction*> transactions;
};
#endif 
