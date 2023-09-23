#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

#include "Transaction.h"
#include "Account.h"

using namespace std;

int findAccount(int ID, const vector<Account*>& accounts);
Account* chooseAccount(vector<Account*>& accounts);
void prizeDrawing(const vector<Account*>& accounts);

vector<Account*> loadAccounts(const string& accountFile);
void saveAccounts(const string& accountFile, const vector<Account*>& accounts);

int main()
{
	enum class Choices { addAccount = 1, addTransaction, getBalance, print, drawPrize, sort, exit };
	string accountFile{ "accounts.txt" };
	vector<Account*> accounts{ loadAccounts(accountFile) };
	int ID;
	int choice{ 0 };

	while ((Choices)choice != Choices::exit)
	{
		cout << "Would you like to: \n"
			<< "  1. Add a new Account\n"
			<< "  2. Add a new Transaction to an existing Account\n"
			<< "  3. Get the current balance of an account\n"
			<< "  4. Print Account & Transactions\n"
			<< "  5. Draw Prize\n"
			<< "  6. Sort Transactions\n"
			<< "  7. Exit\n";
		cin >> choice;
		switch ((Choices)choice)
		{
		case Choices::addAccount:
			accounts.push_back(new Account());
			break;
		case Choices::addTransaction:
			chooseAccount(accounts)->addTransaction();
			break;
		case Choices::getBalance:
			cout << "Your current account balance is: $" << chooseAccount(accounts)->getCurrentBalance() << endl;
			break;
		case Choices::print:
			chooseAccount(accounts)->print();
			break;
		case Choices::drawPrize:
			prizeDrawing(accounts);
			break;
		case Choices::sort:
			ID = chooseAccount(accounts)->getID();
			accounts.at(findAccount(ID, accounts))->sort();
			cout << "Transactions sorted.\n" << endl;
			break;
		default:
			break;
		}
		system("PAUSE");
		system("CLS");
	}
	saveAccounts(accountFile, accounts);

}

int findAccount(int ID, const vector<Account*>& accounts)
{
	for (int i{ 0 }; i < accounts.size(); i++)
	{
		if (accounts.at(i)->getID() == ID)
			return i;
	}
	return -1;
}

Account* chooseAccount(vector<Account*>& accounts)
{
	cout << "Enter the ID of your account: ";
	int ID;
	cin >> ID;

	int accountIndex = findAccount(ID, accounts);
	while (accountIndex == -1)
	{
		cout << "Invalid ID entered. Enter a valid ID: ";
		cin >> ID;
		accountIndex = findAccount(ID, accounts);
	}
	return accounts.at(accountIndex);
}

void prizeDrawing(const vector<Account*>& accounts)
{
	random_device seed;
	default_random_engine e(seed());
	uniform_int_distribution<int> randomAccount(0, accounts.size() - 1);
	int prizeWinner = randomAccount(e);
	cout << "The winner of the prize is " << accounts.at(prizeWinner)->getFirstName() << " " << accounts.at(prizeWinner)->getLastName() << "!\n";
}

vector<Account*> loadAccounts(const string& accountFile)
{
	vector<Account*> accounts;
	ifstream fin;
	fin.open(accountFile);
	if (!fin.is_open())
	{
		cout << "File not found";
		return accounts;
	}
	int lastID;
	fin >> lastID;
	Account::lastID = lastID;
	int numberOfAccounts;
	fin >> numberOfAccounts;
	for (int i{ 0 }; i < numberOfAccounts; i++)
	{
		int ID;
		fin >> ID;
		string firstName;
		fin >> firstName;
		string lastName;
		fin >> lastName;
		float beginningBalance;
		fin >> beginningBalance;
		accounts.push_back(new Account(ID, firstName, lastName, beginningBalance));
		int numberOfTransactions;
		fin >> numberOfTransactions;
		for (int j{ 0 }; j < numberOfTransactions; j++)
		{
			Date date;
			fin >> date.month >> date.day >> date.year;
			string description;
			fin >> description;
			float amount;
			fin >> amount;
			accounts.back()->addTransaction(date, description, amount);
		}
	}
	fin.close();
	return accounts;
}

void saveAccounts(const string& accountFile, const vector<Account*>& accounts)
{
	ofstream fout;
	fout.open(accountFile);
	if (!fout.is_open())
	{
		cout << "ERROR! File not found. Accounts not saved!" << endl;
		system("PAUSE");
		return;
	}
	fout << Account::lastID << endl;
	fout << accounts.size() << endl;
	for (Account* account : accounts)
	{
		fout << account->getID() << " " << account->getFirstName() << " " << account->getLastName() << " " << account->getBeginningBalance() << endl;
		fout << account->getTransactions().size() << endl;
		for (Transaction* transaction : account->getTransactions())
		{
			fout << transaction->getDate().month << " " << transaction->getDate().day << " " << transaction->getDate().year << " " << transaction->getDescription() << " " << transaction->getAmount() << endl;
		}
	}
	fout.close();
}