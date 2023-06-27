d#include <cctype>
#include <algorithm>
#include <vector>
#include <iostream>

int	main(int argc, char *argv[]){
	std::vector<std::string> arguments(argv, argv + argc);
	int (*toupperPtr)(int) = &std::toupper;

	if (argc)
	{
		std::transform(arguments.begin(), arguments.end(), arguments.begin(), toupperPtr);
		for (int i = 0; i < argc; i++)
			std::cout << arguments[i] << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
}
