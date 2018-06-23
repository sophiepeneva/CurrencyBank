# CurrencyBank

#pragma once
#include<iostream>

class Currency
{
public:
	Currency(const char* name = "No name", double rate = 0);
	~Currency() { delete[] name; }
	Currency(const Currency& c) { CopyFrom(c); }
	Currency& operator=(const Currency& c);

	void setName(const char* n);
	void setRate(double r) { rate = r; }

	char* getName() const { return name; }
	double getRate() const { return rate; }
	void print() const { std::cout << name << " " << rate << std::endl; }
private:
	void CopyFrom(const Currency& c);

	char* name;
	double rate;
};
