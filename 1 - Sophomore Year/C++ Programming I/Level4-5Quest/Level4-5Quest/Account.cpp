#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
using namespace std;

Account::Account()
{
	lastID++;
	ID = lastID;
	cout << "Enter the account holder's full name (first name followed by last name): ";
	cin >> firstName >> lastName;
	cout << "Enter the account's beginning balance: ";
	cin >> beginningBalance;
}

Account::Account(int ID, string firstName, string lastName, float beginningBalance)
{
	this->ID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->beginningBalance = beginningBalance;
}

int Account::lastID{ 0 };

void Account::addTransaction()
{
	cout << "Enter the date of the transaction in MM DD YY format: ";
	Date date;
	cin >> date.month >> date.day >> date.year;

	cout << "Enter the description of the transaction: ";
	string description;
	cin >> description;

	cout << "Enter the amount of transaction: ";
	float amount;
	cin >> amount;

	transactions.push_back(Transaction(date, description, amount));
	transactions.back().setValidDate();
}

void Account::addTransaction(Date date, string description, float amount)
{
	transactions.push_back(Transaction(date, description, amount));
	transactions.back().setValidDate();
}

float Account::getCurrentBalance()
{
	float currentBalance{ beginningBalance };
	for (Transaction transaction : transactions)
	{
		currentBalance += transaction.getAmount();
	}
	return currentBalance;
}

int Account::getID() const
{
	return ID;
}

string Account::getFirstName() const
{
	return firstName;
}

string Account::getLastName() const
{
	return lastName;
}

float Account::getBeginningBalance() const
{
	return beginningBalance;
}

vector<Transaction> Account::getTransactions() const
{
	return transactions;
}

void Account::print() const
{
	cout << firstName << " " << lastName << "'s Account Information:\n";
	cout << "First Name: " << firstName << endl;;
	cout << "Last Name: " << lastName << endl;
	cout << "ID: " << ID << endl;
	cout << "Beginning Balance: " << beginningBalance << endl;
	int transactionNumber{ 1 };
	for (Transaction transaction : transactions)
	{
		cout << "\nTransaction " << transactionNumber << ": \n";
		transaction.print();
		transactionNumber++;
	}
}

void Account::sort()
{
	cout << "Do you want to sort the transactions by (1) date, (2) description, or (3) amount?: ";

	Transaction temp({ 0, 0, 0 }, " ", 0);
	int i{ 0 };
	int j{ 0 };

	int userInput{ 0 };
	cin >> userInput;
	switch (userInput)
	{
	case 1:
		i = 0;
		j = 0;
		for (i = 1; i < transactions.size(); i++)
		{
			j = i;
			while (j > 0 && transactions.at(j).compareTwoDates(transactions.at(j - 1).getDate(), transactions.at(j).getDate()))
			{
				temp = transactions.at(j);
				transactions.at(j) = transactions.at(j - 1);
				transactions.at(j - 1) = temp;
				j--;
			}
		}
		temp = { {0, 0, 0}, " ", 0 };
		break;
	case 2:
		i = 0;
		j = 0;
		for (i = 1; i < transactions.size(); i++)
		{
			j = i;
			while (j > 0 && transactions.at(j).getDescription() < transactions.at(j - 1).getDescription())
			{
				temp = transactions.at(j);
				transactions.at(j) = transactions.at(j - 1);
				transactions.at(j - 1) = temp;
				j--;
			}
		}
		temp = { { 0, 0, 0 }, " ", 0 };
		break;
	case 3:
		i = 0;
		j = 0;
		for (i = 1; i < transactions.size(); i++)
		{
			j = i;
			while (j > 0 && transactions.at(j).getAmount() < transactions.at(j - 1).getAmount())
			{
				temp = transactions.at(j);
				transactions.at(j) = transactions.at(j - 1);
				transactions.at(j - 1) = temp;
				j--;
			}
		}
		break;
	}
}
