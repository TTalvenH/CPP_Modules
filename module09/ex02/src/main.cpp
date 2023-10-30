#include "./PmergeMe/PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc > 2)
	{
		PmergeMe sorter(argc - 1, ++argv);

		sorter.sort();
	}
	else
		std::cout << "Error: incorrect amount of arguments." << std::endl;
	return 0;
}