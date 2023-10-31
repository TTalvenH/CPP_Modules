#include "./RPN/RPN.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		try
		{
		RPN RpnCalculator;

		RpnCalculator.calculate(argv[1]);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: incorrect amount of arguments." << std::endl;
	return 0;
}