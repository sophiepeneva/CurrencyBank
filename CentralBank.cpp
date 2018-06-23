# CurrencyBank

#include "CentralBank.h"



CentralBank::CentralBank(const char* name, std::vector<Currency> currencies,
	std::vector<Observer*> observers)
{
	setName(name);
	this->currencies = currencies;
	for(int i=0;i<observers.size();i++)
	{
		this->observers[i] = observers[i];
	}
}

void CentralBank::CopyFrom(const CentralBank& cB)
{
	setName(cB.name);
	currencies = cB.currencies;
	for (int i = 0; i<observers.size(); i++)
	{
		observers[i] = cB.observers[i];
	}
}

void CentralBank::setName(const char* n)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}


void CentralBank::setRate(const Currency& c)
{
	for(int i=0;i<currencies.size();i++)
	{
		if (strcmp(currencies[i].getName(), c.getName()) == 0) 
		{
			currencies[i].setRate(c.getRate());
			notify(currencies[i]);
		}
	}
	
}

void CentralBank::deleteCurrency(const Currency& c)
{
	int index = -1;
	for (int i = 0; i<currencies.size(); i++)
	{
		if (strcmp(currencies[i].getName(), c.getName()) == 0)index = i;
	}
	if (index != -1) currencies.erase(currencies.begin() + index);
	else { std::cout << "Action failed : There is no currency with this name"; }
}


void CentralBank::Destroy()
{
	delete[] name;
}

void CentralBank::printCurrencies() const
{
	for (int i = 0; i < currencies.size(); i++)currencies[i].print();
}

void CentralBank::notify(const Currency& c) const
{
	for (int i = 0; i < observers.size(); i++)observers[i]->update(c);
}

void CentralBank::registerObserver(const Observer& o)
{
	ConcreteObserver* cO = new ConcreteObserver(o.getName());
	observers.push_back(cO);
}

void CentralBank::unregister(const Observer& o)
{
	int index = -1;
	for (int i = 0; i < observers.size(); i++)
	{
		if (strcmp(observers[i]->getName(), o.getName()) == 0)index = i;
	}
	if (index != -1) observers.erase(observers.begin() + index);
	else { std::cout << "Action failed : There is no observer with this name"; }
}
