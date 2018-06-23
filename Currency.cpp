# CurrencyBank

#include "Currency.h"

Currency& Currency::operator=(const Currency& c)
{
	if (this != &c)
	{
		delete[] name;
		CopyFrom(c);
	}
	return *this;
}

Currency::Currency(const char* name, double r) : rate(r)
{
	setName(name);
}

void Currency::setName(const char* n)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}


void Currency::CopyFrom(const Currency& c)
{
	setName(c.name);
	rate = c.rate;
}
