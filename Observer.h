# CurrencyBank

#pragma once
#include<iostream>
#include "Currency.h"

class Observer
{
public:
	Observer(const char* name = "No name") { setName(name); }
	Observer(const Observer& o) { CopyFrom(o); }
	Observer& operator=(const Observer& cO);
	virtual ~Observer() { delete[] name; };

	void setName(const char* n);
	char* getName() const { return name; }

	virtual void update(const Currency& c) const = 0;
	virtual void print()const = 0;
private:
	void CopyFrom(const Observer& cO);

	char* name;
};
