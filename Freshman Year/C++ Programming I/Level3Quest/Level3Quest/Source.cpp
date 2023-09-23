#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct Date
{
	int month;
	int day;
	int year;
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

void setValidDate(int& month, int& day, int& year);
Transaction addTransaction();
Account newAccount(int& lastID);
float getCurrentBalance(const Account& account);

void sortAccountsByID(vector<Account>& accounts);
int findAccountByID(int ID, vector<Account>& accounts);

void listTransactions(const Account& account);

void editAccountInformation(int ID, vector<Account>& accounts);
void editAccountInformation(string lastName, vector<Account>& accounts);

void editTransactionInformation(Date date, vector<Transaction>& transactions);
void editTransactionInformation(string description, vector<Transaction>& transactions);
void editTransactionInformation(float amount, vector<Transaction>& transactions);

void sortAccountsByLastName(vector<Account>& accounts);
int findAccountByLastName(string lastName, vector<Account>& accounts);
vector<Account> findListOfAccountsByLastName(string lastName, vector<Account>& accounts);
int askUserToSelectAnAccountByLastName(string lastName, vector<Account>& accounts);

void sortTransactionByDate(vector<Transaction>& transactions);
bool compareTwoDates(Date date1, Date date2);
bool checkIfTwoDatesAreEqual(Date date1, Date date2);
int findTransactionByDate(Date date, vector<Transaction>& transactions);
vector <Transaction> findListOfTransactionsByDate(Date date, vector<Transaction>& transactions);
int askUserToSelectATransactionByDate(Date date, vector<Transaction>& transactons);

void sortTransactionByDescription(vector<Transaction>& transactions);
int findTransactionByDescription(string description, vector<Transaction>& transactions);
vector <Transaction> findListOfTransactionsByDescription(string description, vector<Transaction>& transactions);
int askUserToSelectATransactionByDescription(string description, vector<Transaction>& transactons);

void sortTransactionByAmount(vector<Transaction>& transactions);
int findTransactionByAmount(float amount, vector<Transaction>& transactions);
vector <Transaction> findListOfTransactionsByAmount(float amount, vector<Transaction>& transactions);
int askUserToSelectATransactionByAmount(float amount, vector<Transaction>& transactons);

int main()
{
	vector<Account> accounts;
	int ID{ 0 };
	int userInput{ 1 };
	while (userInput >= 1 && userInput <= 6)
	{
		cout << "1. Add account\n";
		cout << "2. Add Transaction\n";
		cout << "3. Get Balance\n";
		cout << "4. List Transactions\n";
		cout << "5. Edit Account Information\n";
		cout << "6. Edit Transaction Information\n";
		cout << "7. Exit Program\n";
		cout << "Choose an option from the menu by typing its corresponding number: ";
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			accounts.push_back(newAccount(ID));
			break;

		case 2:
			cout << "Do you know the ID of the account that you want to add the transaction to? (Y/N): ";
			char input;
			cin >> input;
			if (input == 'Y' || input == 'y')
			{
				cout << "Enter the ID of the account: ";
				int inputtedID;
				cin >> inputtedID;
				int index{ findAccountByID(ID, accounts) };
				accounts.at(index).transactions.push_back(addTransaction());
			}
			else
			{
				cout << "Enter the last name of the account: ";
				string inputtedLastName;
				cin >> inputtedLastName;
				int index{ askUserToSelectAnAccountByLastName(inputtedLastName, accounts) };
				accounts.at(index).transactions.push_back(addTransaction());
			}
			break;

		case 3:
			cout << "Do you know the ID of the account that you want the balance of? (Y/N): ";
			cin >> input;
			if (input == 'Y' || input == 'y')
			{
				cout << "Enter the ID of the account: ";
				int inputtedID;
				cin >> inputtedID;
				int index{ findAccountByID(ID, accounts) };
				cout << "\nCurrent Balance: " << getCurrentBalance(accounts.at(index)) << endl;
			}
			else
			{
				cout << "Enter the last name of the account: ";
				string inputtedLastName;
				cin >> inputtedLastName;
				int index{ askUserToSelectAnAccountByLastName(inputtedLastName, accounts) };
				cout << "\nCurrent Balance: " << getCurrentBalance(accounts.at(index)) << endl;
			}
			break;

		case 4:
			cout << "Do you know the ID of the account that you want to list the transactions of? (Y/N): ";
			cin >> input;
			if (input == 'Y' || input == 'y')
			{
				cout << "Enter the ID of the account: ";
				int inputtedID;
				cin >> inputtedID;
				int index{ findAccountByID(ID, accounts) };
				cout << endl;
				listTransactions(accounts.at(index));
			}
			else
			{
				cout << "Enter the last name of the account: ";
				string inputtedLastName;
				cin >> inputtedLastName;
				int index{ askUserToSelectAnAccountByLastName(inputtedLastName, accounts) };
				cout << endl;
				listTransactions(accounts.at(index));
			}
			break;

		case 5:
			cout << "Do you know the ID of the account that you want edit? (Y/N): ";
			cin >> input;
			if (input == 'Y' || input == 'y')
			{
				cout << "Enter the ID of the account: ";
				int inputtedID;
				cin >> inputtedID;
				editAccountInformation(inputtedID, accounts);
			}
			else
			{
				cout << "Enter the last name of the account: ";
				string inputtedLastName;
				cin >> inputtedLastName;
				editAccountInformation(inputtedLastName, accounts);
			}
			break;

		case 6:
			cout << "Do you know the ID of the account that you want edit? (Y/N): ";
			cin >> input;
			int index;
			if (input == 'Y' || input == 'y')
			{
				cout << "Enter the ID of the account: ";
				int inputtedID;
				cin >> inputtedID;
				index = findAccountByID(ID, accounts);
			}
			else
			{
				cout << "Enter the last name of the account: ";
				string inputtedLastName;
				cin >> inputtedLastName;
				index = askUserToSelectAnAccountByLastName(inputtedLastName, accounts);
			}
			int searchChoice{ 0 };
			while (searchChoice < 1 || searchChoice > 3)
			{
				cout << "Do you want to find the transaction you want to edit by searching for its (1) date, (2) description, or (3) amount? (Enter the number that corresponds to your choice): ";
				cin >> searchChoice;
			}
			switch (searchChoice)
			{
			case 1:
				cout << "Enter the date of the transaction in MM DD YY format: ";
				Date inputtedDate;
				cin >> inputtedDate.month >> inputtedDate.day >> inputtedDate.year;
				editTransactionInformation(inputtedDate, accounts.at(index).transactions);
				break;
			case 2:
			{
				cout << "Enter the description of the transaction: ";
				string inputtedDescription;
				cin >> inputtedDescription;
				editTransactionInformation(inputtedDescription, accounts.at(index).transactions);
				break;
			}
			case 3:
				cout << "Enter the amount of the transaction: ";
				float inPuttedamount;
				cin >> inPuttedamount;
				editTransactionInformation(inPuttedamount, accounts.at(index).transactions);
				break;
			}
			break;
		}
		cout << endl;
	}
}

void setValidDate(int& month, int& day, int& year)
{
	
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 1 || day > 31)
		{
			month = 12;
			day = 31;
			year = 2019;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
		{
			month = 12;
			day = 31;
			year = 2019;
		}
	}
	else if (month == 2)
	{
		if (year % 4 == 0 && (!(year % 100 == 0) || year % 400 == 0))
		{
			if (day < 1 || day > 29)
			{
				month = 12;
				day = 31;
				year = 2019;
			}
		}
		else
		{
			if (day < 1 || day > 28)
			{
				month = 12;
				day = 31;
				year = 2019;
			}
		}
	}
	
}

Transaction addTransaction()
{
	cout << "Enter the date of the transaction in MM DD YY format: ";
	int month;
	int day;
	int year;
	cin >> month >> day >> year;
	setValidDate(month, day, year);

	cout << "Enter the description of the transaction: ";
	string description;
	cin >> description;

	cout << "Enter the amount of transaction: ";
	float amount;
	cin >> amount;

	return { {month, day, year}, description, amount };
}

Account newAccount(int& lastID)
{
	lastID++;

	cout << "Enter the first name of the account: ";
	string firstName;
	cin >> firstName;

	cout << "Enter the last name of the account: ";
	string lastName;
	cin >> lastName;

	cout << "Enter the beginning balance of the account: ";
	float beginningBalance;
	cin >> beginningBalance;

	return { lastID, firstName, lastName, beginningBalance };
}

float getCurrentBalance(const Account& account)
{
	float currentBalance{ account.beginningBalance };
	for (Transaction transaction : account.transactions)
	{
		currentBalance += transaction.amount;
	}
	return currentBalance;
}

void sortAccountsByID(vector <Account>& accounts)
{
	int i{ 0 };
	int j{ 0 };
	Account temp;
	for (i = 1; i < accounts.size(); i++)
	{
		j = i;
		while (j > 0 && accounts.at(j).ID < accounts.at(j - 1).ID)
		{
			temp = accounts.at(j);
			accounts.at(j) = accounts.at(j - 1);
			accounts.at(j - 1) = temp;
			j--;
		}
	}
}

int findAccountByID(int ID, vector <Account> & accounts)
{
	sortAccountsByID(accounts);
	int mid;
	int low { 0 };
	int high = accounts.size() - 1 ;

	while (high >= low)
	{
		mid = (high + low) / 2;
		if (accounts.at(mid).ID < ID)
		{
			low = mid + 1;
		}
		else if (accounts.at(mid).ID > ID)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
}

void listTransactions(const Account& account)
{
	cout << account.firstName << " " << account.lastName << "'s Account Information:\n";
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
}

void editAccountInformation(int ID, vector<Account>& accounts)
{
	int account { findAccountByID(ID, accounts) };

	cout << "Do you want to change the ID of the account? (y/n): ";
	char userInput;
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new ID of the account: ";
		cin >> accounts.at(account).ID;
	}

	cout << "Do you want to change the first name of the account? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new first name of the account: ";
		cin >> accounts.at(account).firstName;
	}

	cout << "Do you want to change the last name of the account? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new last name of the account: ";
		cin >> accounts.at(account).lastName;
	}

	cout << "Do you want to change the beginning balance of the account? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new beginning balance of the account: ";
		cin >> accounts.at(account).beginningBalance;
	}
}

void editAccountInformation(string lastName, vector<Account>& accounts)
{
	int account { askUserToSelectAnAccountByLastName(lastName, accounts) };

	cout << "Do you want to change the ID of the account? (y/n): ";
	char userInput;
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new ID of the account: ";
		cin >> accounts.at(account).ID;
	}

	cout << "Do you want to change the first name of the account? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new first name of the account: ";
		cin >> accounts.at(account).firstName;
	}

	cout << "Do you want to change the last name of the account? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new last name of the account: ";
		cin >> accounts.at(account).lastName;
	}

	cout << "Do you want to change the beginning balance of the account? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new beginning balance of the account: (y/n): ";
		cin >> accounts.at(account).beginningBalance;
	}
}

void editTransactionInformation(Date date, vector<Transaction>& transactions)
{
	int transaction{ askUserToSelectATransactionByDate(date, transactions) };
	cout << "Do you want to change the date of the transaction? (y/n): ";
	char userInput;
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new date of the transaction in MM DD YY format: ";
		cin >> transactions.at(transaction).date.month >> transactions.at(transaction).date.day >> transactions.at(transaction).date.year;
		setValidDate(transactions.at(transaction).date.month, transactions.at(transaction).date.day, transactions.at(transaction).date.year);
	}
	cout << "Do you want to change the description of the transaction? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new description of the transaction: ";
		cin >> transactions.at(transaction).description;
	}
	cout << "Do you want to change the amount of the transaction? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new amount of the transaction: ";
		cin >> transactions.at(transaction).amount;
	}
}

void editTransactionInformation(string description, vector<Transaction>& transactions)
{
	int transaction{ askUserToSelectATransactionByDescription(description, transactions) };
	cout << "Do you want to change the date of the transaction? (y/n): ";
	char userInput;
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new date of the transaction in MM DD YY format: ";
		cin >> transactions.at(transaction).date.month >> transactions.at(transaction).date.day >> transactions.at(transaction).date.year;
		setValidDate(transactions.at(transaction).date.month, transactions.at(transaction).date.day, transactions.at(transaction).date.year);
	}
	cout << "Do you want to change the description of the transaction? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new description of the transaction: ";
		cin >> transactions.at(transaction).description;
	}
	cout << "Do you want to change the amount of the transaction? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new amount of the transaction: ";
		cin >> transactions.at(transaction).amount;
	}
}

void editTransactionInformation(float amount, vector<Transaction>& transactions)
{
	int transaction{ askUserToSelectATransactionByAmount(amount, transactions) };
	cout << "Do you want to change the date of the transaction? (y/n): ";
	char userInput;
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new date of the transaction in MM DD YY format: ";
		cin >> transactions.at(transaction).date.month >> transactions.at(transaction).date.day >> transactions.at(transaction).date.year;
		setValidDate(transactions.at(transaction).date.month, transactions.at(transaction).date.day, transactions.at(transaction).date.year);
	}
	cout << "Do you want to change the description of the transaction? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new description of the transaction: ";
		cin >> transactions.at(transaction).description;
	}
	cout << "Do you want to change the amount of the transaction? (y/n): ";
	cin >> userInput;
	if (userInput == 'y' || userInput == 'Y')
	{
		cout << "Enter the new amount of the transaction: ";
		cin >> transactions.at(transaction).amount;
	}
}

void sortAccountsByLastName(vector<Account>& accounts)
{
	int i{ 0 };
	int j{ 0 };
	Account temp;
	for (i = 1; i < accounts.size(); i++)
	{
		j = i;
		while (j > 0 && accounts.at(j).lastName < accounts.at(j - 1).lastName)
		{
			temp = accounts.at(j);
			accounts.at(j) = accounts.at(j - 1);
			accounts.at(j - 1) = temp;
			j--;
		}
	}
}

int findAccountByLastName(string lastName, vector<Account>& accounts)
{
	sortAccountsByLastName(accounts);
	int mid;
	int low{ 0 };
	int high = accounts.size() - 1;

	while (high >= low)
	{
		mid = (high + low) / 2;
		if (accounts.at(mid).lastName < lastName)
		{
			low = mid + 1;
		}
		else if (accounts.at(mid).lastName > lastName)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
}

vector<Account> findListOfAccountsByLastName(string lastName, vector<Account>& accounts)
{
	int firstFound = { findAccountByLastName(lastName, accounts) };
	vector<Account> found;
	int index { firstFound + 1 };
	found.push_back(accounts.at(firstFound));

	while (index < accounts.size() && accounts.at(index).lastName == accounts.at(firstFound).lastName)
	{
		found.push_back(accounts.at(index));
		index++;
	}
	index = firstFound - 1;

	while (index >= 0 && accounts.at(index).lastName == accounts.at(firstFound).lastName)
	{
		found.push_back(accounts.at(index));
		index--;
	}
	return found;

}

int askUserToSelectAnAccountByLastName(string lastName, vector<Account>& accounts)
{
	vector<Account> found { findListOfAccountsByLastName(lastName, accounts) };

	int accountNumber{ 1 };
	int userInput;
	cout << "The accounts that match this last name are: \n";
	for (Account account : found)
	{
		cout << "\nAccount Number " << accountNumber << ": \n";
		cout << "ID: " << account.ID << endl;
		cout << "First Name: " << account.firstName << endl;
		cout << "Last Name: " << account.lastName << endl;
		cout << "Beginning Balance: " << account.beginningBalance << endl;
		accountNumber++;
	}
	cout << "Choose the account you were searching for by typing its number: ";
	cin >> userInput;
	return userInput - 1;
		
}

void sortTransactionByDate(vector<Transaction>& transactions)
{
	int i{ 0 };
	int j{ 0 };
	Transaction temp;
	for (i = 1; i < transactions.size(); i++)
	{
		j = i;
		while (j > 0 && compareTwoDates(transactions.at(j - 1).date, transactions.at(j).date))
		{
			temp = transactions.at(j);
			transactions.at(j) = transactions.at(j - 1);
			transactions.at(j - 1) = temp;
			j--;
		}
	}
}

bool compareTwoDates(Date date1, Date date2)
{
	if (date1.year != date2.year)
	{
		return date1.year > date2.year;
	}
	if (date1.month != date2.month)
	{
		return date1.month > date2.month;
	}
	return date1.day > date2.day;
}

bool checkIfTwoDatesAreEqual(Date date1, Date date2)
{
	if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
	{
		return true;
	}
	return false;
}

int findTransactionByDate(Date date, vector<Transaction>& transactions)
{
	sortTransactionByDate(transactions);
	int mid;
	int low { 0 };
	int high = transactions.size() - 1;

	while (high >= low)
	{
		mid = (high + low) / 2;
		if (compareTwoDates(date, transactions.at(mid).date))
		{
			low = mid + 1;
		}
		else if (compareTwoDates(transactions.at(mid).date, date))
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
}

vector<Transaction> findListOfTransactionsByDate(Date date, vector<Transaction>& transactions)
{
	int firstFound = { findTransactionByDate(date, transactions) };
	vector<Transaction> found;
	int index{ firstFound + 1 };
	found.push_back(transactions.at(firstFound));

	while (index < transactions.size() && checkIfTwoDatesAreEqual(transactions.at(index).date, transactions.at(firstFound).date))
	{
		found.push_back(transactions.at(index));
		index++;
	}
	index = firstFound - 1;

	while (index >= 0 && checkIfTwoDatesAreEqual(transactions.at(index).date, transactions.at(firstFound).date))
	{
		found.push_back(transactions.at(index));
		index--;
	}
	return found;
}

int askUserToSelectATransactionByDate(Date date, vector<Transaction>& transactions)
{
	vector<Transaction> found{ findListOfTransactionsByDate(date, transactions) };

	int transactionNumber{ 1 };
	int userInput;
	cout << "The transactions that match this date are: \n";
	for (Transaction transaction : found)
	{
		cout << "\nTransaction Number " << transactionNumber << ": \n";
		cout << "Date: " << transaction.date.month << "/" << transaction.date.day << "/" << transaction.date.year << endl;
		cout << "Description: " << transaction.description << endl;
		cout << "Amount: " << transaction.amount << endl;
		transactionNumber++;
	}
	cout << "Choose the transaction you were searching for by typing its number: ";
	cin >> userInput;
	return userInput - 1;
}

void sortTransactionByDescription(vector<Transaction>& transactions)
{
	int i{ 0 };
	int j{ 0 };
	Transaction temp;
	for (i = 1; i < transactions.size(); i++)
	{
		j = i;
		while (j > 0 && transactions.at(j).description < transactions.at(j - 1).description)
		{
			temp = transactions.at(j);
			transactions.at(j) = transactions.at(j - 1);
			transactions.at(j - 1) = temp;
			j--;
		}
	}
}

int findTransactionByDescription(string description, vector<Transaction>& transactions)
{
	sortTransactionByDescription(transactions);
	int mid;
	int low{ 0 };
	int high = transactions.size() - 1;

	while (high >= low)
	{
		mid = (high + low) / 2;
		if (transactions.at(mid).description < description)
		{
			low = mid + 1;
		}
		else if (transactions.at(mid).description > description)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
}

vector <Transaction> findListOfTransactionsByDescription(string description, vector<Transaction>& transactions)
{
	int firstFound = { findTransactionByDescription(description, transactions) };
	vector<Transaction> found;
	int index{ firstFound + 1 };
	found.push_back(transactions.at(firstFound));

	while (index < transactions.size() && transactions.at(index).description == transactions.at(firstFound).description)
	{
		found.push_back(transactions.at(index));
		index++;
	}
	index = firstFound - 1;

	while (index >= 0 && transactions.at(index).description == transactions.at(firstFound).description)
	{
		found.push_back(transactions.at(index));
		index--;
	}
	return found;
}

int askUserToSelectATransactionByDescription(string description, vector<Transaction>& transactons)
{
	vector<Transaction> found{ findListOfTransactionsByDescription(description, transactons) };

	int transactionNumber{ 1 };
	int userInput;
	cout << "The transactions that match this last name are: \n";
	for (Transaction transaction : found)
	{
		cout << "\nTransaction Number " << transactionNumber << ": \n";
		cout << "Date: " << transaction.date.month << "/" << transaction.date.day << "/" << transaction.date.year << endl;
		cout << "Description: " << transaction.description << endl;
		cout << "Amount: " << transaction.amount << endl;
		transactionNumber++;
	}
	cout << "Choose the transaction you were searching for by typing its number: ";
	cin >> userInput;
	return userInput - 1;
}

void sortTransactionByAmount(vector<Transaction>& transactions)
{
	int i{ 0 };
	int j{ 0 };
	Transaction temp;
	for (i = 1; i < transactions.size(); i++)
	{
		j = i;
		while (j > 0 && transactions.at(j).amount < transactions.at(j - 1).amount)
		{
			temp = transactions.at(j);
			transactions.at(j) = transactions.at(j - 1);
			transactions.at(j - 1) = temp;
			j--;
		}
	}
}

int findTransactionByAmount(float amount, vector<Transaction>& transactions)
{
	sortTransactionByAmount(transactions);
	int mid;
	int low{ 0 };
	int high = transactions.size() - 1;

	while (high >= low)
	{
		mid = (high + low) / 2;
		if (transactions.at(mid).amount < amount)
		{
			low = mid + 1;
		}
		else if (transactions.at(mid).amount > amount)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
}

vector <Transaction> findListOfTransactionsByAmount(float amount, vector<Transaction>& transactions)
{
	int firstFound = { findTransactionByAmount(amount, transactions) };
	vector<Transaction> found;
	int index{ firstFound + 1 };
	found.push_back(transactions.at(firstFound));

	while (index < transactions.size() && transactions.at(index).amount == transactions.at(firstFound).amount)
	{
		found.push_back(transactions.at(index));
		index++;
	}
	index = firstFound - 1;

	while (index >= 0 && transactions.at(index).amount == transactions.at(firstFound).amount)
	{
		found.push_back(transactions.at(index));
		index--;
	}
	return found;
}

int askUserToSelectATransactionByAmount(float amount, vector<Transaction>& transactons)
{
	vector<Transaction> found{ findListOfTransactionsByAmount(amount, transactons) };

	int transactionNumber{ 1 };
	int userInput;
	cout << "The transactions that match this last name are: \n";
	for (Transaction transaction : found)
	{
		cout << "\nTransaction Number " << transactionNumber << ": \n";
		cout << "Date: " << transaction.date.month << "/" << transaction.date.day << "/" << transaction.date.year << endl;
		cout << "Description: " << transaction.description << endl;
		cout << "Amount: " << transaction.amount << endl;
		transactionNumber++;
	}
	cout << "Choose the transaction you were searching for by typing its number: ";
	cin >> userInput;
	return userInput - 1;
}