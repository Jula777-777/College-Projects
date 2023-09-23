#include <iostream>
#include <string>
#include "Transaction.h"
using namespace std;

Transaction::Transaction(Date date, string description, float amount)
{
	this->date = date;
	this->description = description;
	this->amount = amount;
}

float Transaction::getAmount() const
{
	return amount;
}

Date Transaction::getDate() const
{
	return date;
}

string Transaction::getDescription() const
{
	return description;
}

void Transaction::print() const
{
	cout << "Date: " << date.month << "/" << date.day << "/" << date.year << endl;
	cout << "Description: " << description << endl;
	cout << "Amount: " << amount << endl;
}

void Transaction::setValidDate()
{

	if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12)
	{
		if (date.day < 1 || date.day > 31)
		{
			date.month = 12;
			date.day = 31;
			date.year = 2019;
		}
	}
	else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
	{
		if (date.day < 1 || date.day > 30)
		{
			date.month = 12;
			date.day = 31;
			date.year = 2019;
		}
	}
	else if (date.month == 2)
	{
		if (date.year % 4 == 0 && (!(date.year % 100 == 0) || date.year % 400 == 0))
		{
			if (date.day < 1 || date.day > 29)
			{
				date.month = 12;
				date.day = 31;
				date.year = 2019;
			}
		}
		else
		{
			if (date.day < 1 || date.day > 28)
			{
				date.month = 12;
				date.day = 31;
				date.year = 2019;
			}
		}
	}
	else
	{
		date.month = 12;
		date.day = 31;
		date.year = 2019;
	}

}

bool Transaction::compareTwoDates(Date date1, Date date2)
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