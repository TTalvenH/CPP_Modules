#include "./ScalarConverter/ScalarConverter.hpp"


int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::string input = argv[1];

		ScalarConverter::convert(input);
	}
	return 0;
}