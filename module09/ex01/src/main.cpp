#include "./RPN/RPN.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		RPN RpnCalculator;

		RpnCalculator.calculate(argv[1]);
	}
	else
		std::cout << "Error: incorrect amount of arguments." << std::endl;
	return 0;
}