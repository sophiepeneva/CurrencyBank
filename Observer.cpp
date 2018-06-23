# CurrencyBank

#include "Observer.h"


void Observer::setName(const char* n)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}



void Observer::CopyFrom(const Observer& o)
{
	setName(o.name);
}

Observer& Observer::operator=(const Observer& o)
{
	if (this != &o)
	{
		delete[] name;
		CopyFrom(o);
	}
	return *this;
}
