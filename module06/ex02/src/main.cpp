#include "./Base/Base.hpp"
#include <iostream>

int main()
{
	Base* randomClass = generate();
	Base& refToClass = *randomClass;
	identify(randomClass);
	identify(refToClass);
}