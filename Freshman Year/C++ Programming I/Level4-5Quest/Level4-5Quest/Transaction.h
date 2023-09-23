#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

struct Date
{
	int month;
	int day;
	int year;
};

class Transaction
{
public:
	Transaction() = delete;
	Transaction(Date date, std::string description, float amount);
	float getAmount() const;
	Date getDate() const;
	std::string getDescription() const;
	void print() const;
	void setValidDate();
	bool compareTwoDates(Date date1, Date date2);
private:
	Date date;
	std::string description;
	float amount;
};
#endif
