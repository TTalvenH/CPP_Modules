#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base(){}

A::~A(){ delete (this); }
B::~B(){ delete (this); }
C::~C(){ delete (this); }

Base* generate(void)
{
	srand(std::time(NULL));
	int	_randomValue = (rand() % 3);
	if (_randomValue == 0){ return new A; }
	if (_randomValue == 1){ return new B; }
	if (_randomValue == 2){ return new C; }
	return NULL;
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p)){ std::cout << "A" << std::endl; }
	if(dynamic_cast<B*>(p)){ std::cout << "B" << std::endl; }
	if(dynamic_cast<C*>(p)){ std::cout << "C" << std::endl; }
}
void identify(Base& p)
{
	try { dynamic_cast<A&>(p); std::cout << "A" << std::endl; } catch (std::exception& e) {}
	try { dynamic_cast<B&>(p); std::cout << "B" << std::endl; } catch (std::exception& e) {}
	try { dynamic_cast<C&>(p); std::cout << "C" << std::endl; } catch (std::exception& e) {}
}
