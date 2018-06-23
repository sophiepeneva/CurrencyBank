# CurrencyBank

#include<iostream>
#include "Currency.h"
#include "CentralBank.h"
#include "ConcreteObserver.h"

using namespace std;

int main()
{
	Currency cE("euro", 1.95);
	Currency cP("pound", 2.3);
	CentralBank bnb("BNB");
	bnb.addCurrency(cE);
	bnb.addCurrency(cP);
	ConcreteObserver Sophie("Sophie");
	ConcreteObserver Bobby("Bobby");
	bnb.registerObserver(Sophie);
	bnb.registerObserver(Bobby);
	cP.setRate(2.27);
	bnb.setRate(cP);
	bnb.unregister(Bobby);
	cP.setRate(2.3);
	bnb.setRate(cP);
	system("pause");
}
