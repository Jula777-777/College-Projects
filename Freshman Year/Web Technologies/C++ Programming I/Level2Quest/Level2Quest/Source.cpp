#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

struct Transaction
{
	Date date;
	string description;
	float amount;
};

struct Account
{
	int ID;
	string firstName;
	string lastName;
	float beginningBalance;
	vector <Transaction> transactions;
};

int main()
{
	Account account;

	cout << "Enter the ID of the account: ";
	cin >> account.ID;

	cout << "Enter the first name of the account: ";
	cin >> account.firstName;

	cout << "Enter the last name of the account: ";
	cin >> account.lastName;

	cout << "Enter the beginning balance of the account: ";
	cin >> account.beginningBalance;

	int day;
	int month;
	int year;

	for (int transactionNumber{ 1 }; transactionNumber <= 4; transactionNumber++)
	{
		account.transactions.push_back(Transaction());

		cout << "Enter the date of transaction " << transactionNumber << " in month day year format: ";
		cin >> month >> day >> year;

		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day >= 1 && day <= 31)
			{
				account.transactions.back().date.month = month;
				account.transactions.back().date.day = day;
				account.transactions.back().date.year = year;
			}
			else
			{
				account.transactions.back().date.month = 12;
				account.transactions.back().date.day = 31;
				account.transactions.back().date.year = 2019;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day >= 1 && day <= 30)
			{
				account.transactions.back().date.month = month;
				account.transactions.back().date.day = day;
				account.transactions.back().date.year = year;
			}
			else
			{
				account.transactions.back().date.month = 12;
				account.transactions.back().date.day = 31;
				account.transactions.back().date.year = 2019;
			}
		}
		else if (month == 2)
		{
			if (year % 4 == 0 && (!(year % 100 == 0) || year % 400 == 0))
			{
				if (day >= 1 && day <= 29)
				{
					account.transactions.back().date.month = month;
					account.transactions.back().date.day = day;
					account.transactions.back().date.year = year;
				}
				else
				{
					account.transactions.back().date.month = 12;
					account.transactions.back().date.day = 31;
					account.transactions.back().date.year = 2019;
				}
			}
			else
			{
				if (day >= 1 && day <= 28)
				{
					account.transactions.back().date.month = month;
					account.transactions.back().date.day = day;
					account.transactions.back().date.year = year;
				}
				else
				{
					account.transactions.back().date.month = 12;
					account.transactions.back().date.day = 31;
					account.transactions.back().date.year = 2019;
				}
			}
		}
		else
		{
			account.transactions.back().date.month = 12;
			account.transactions.back().date.day = 31;
			account.transactions.back().date.year = 2019;
		}
		cout << "Enter the description of transaction " << transactionNumber << ": ";
		cin >> account.transactions.back().description;

		cout << "Enter the amount of transaction " << transactionNumber << ": ";
		cin >> account.transactions.back().amount;
		
	}

	cout << endl << account.firstName << " " << account.lastName << "'s Account Information:\n";
	cout << "First Name: " << account.firstName << endl;;
	cout << "Last Name: " << account.lastName << endl;
	cout << "ID: " << account.ID << endl;
	cout << "Beginning Balance: " << account.beginningBalance << endl;

	int transactionNumber{ 1 };
	for (Transaction transaction : account.transactions)
	{
		cout << "\nTransaction " << transactionNumber << ": \n";
		cout << "Date: " << transaction.date.month << "/" << transaction.date.day << "/" << transaction.date.year << endl;
		cout << "Description: " << transaction.description << endl;
		cout << "Amount: " << transaction.amount << endl;
		transactionNumber++;
	}
	return 0;
}