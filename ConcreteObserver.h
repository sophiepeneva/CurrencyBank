# CurrencyBank

#pragma once
#include "Observer.h"

class ConcreteObserver :
	public Observer
{
public:
	ConcreteObserver(const char* name = "No name") : Observer(name) {}

	void update(const Currency& c) const;
	void print() const { std::cout << getName() << std::endl; }
};
