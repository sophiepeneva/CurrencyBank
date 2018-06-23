# CurrencyBank

#include "ConcreteObserver.h"

void ConcreteObserver::update(const Currency& c) const
{ 
	std::cout << getName() << " : " << c.getName() << " " << c.getRate() << std::endl; 
}
