#include <iostream>
#include <PhoneBook.hpp>
#include <limits>
#include <cstdlib>

int	main()
{
	std::string	Input;
	PhoneBook phoneBook;

	while (1)
	{
		std::cout << "PhoneBook (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, Input);
		if (std::cin.eof() || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            exit(0);
        }
		if (Input == "ADD")
			phoneBook.addContact();
		if (Input == "SEARCH")
			phoneBook.search();
		if (Input == "EXIT")
			break ;
	}
}