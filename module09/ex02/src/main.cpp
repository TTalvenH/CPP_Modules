#include "./PmergeMe/PmergeMe.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char** argv)
{
	if (argc > 2)
	{
		try{
		for (int i = 1; i < argc; i++)
		{
			int value;
			std::istringstream stream(argv[i]);
			if (!(stream >> value) || value <= 0 || !stream.eof())
				throw std::runtime_error("Error");
		}

		PmergeMe sorter(argc - 1, ++argv);

		sorter.sort();
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