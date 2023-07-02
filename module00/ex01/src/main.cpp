#include <iostream>
#include <PhoneBook.hpp>
#include <limits>

int	main()
{
	std::string	Input;
	PhoneBook phoneBook;

	while (1)
	{
		std::cout << "PhoneBook (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, Input);
		if (Input == "ADD")
			phoneBook.addContact();
		if (Input == "SEARCH")
			phoneBook.search();
		if (Input == "EXIT")
			break ;
	}
}