#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
{	
	contactIndex = 0;
	contactOldest = 0;
}

PhoneBook::~PhoneBook()
{	
}

int	PhoneBook::addContact()
{
	if (contactIndex == 8)
		contactIndex = contactOldest++;
	if (contactOldest == 8)
		contactOldest = 0;
	contacts[contactIndex].setFirstName(askContactInfo("first name"));
	contacts[contactIndex].setFirstName(askContactInfo("last name"));
	contacts[contactIndex].setFirstName(askContactInfo("nickname"));
	contacts[contactIndex].setFirstName(askContactInfo("phonenumber"));
	contacts[contactIndex].setFirstName(askContactInfo("dark secret"));
	contactIndex++;
	return (0);
}

int PhoneBook::search()
{
	for (size_t i = 0; i < 8; i++)
	{
		if (contacts[i].isEmpty())
			continue ;
		std::cout << std::setw(10) << std::right << i << '|';
		std::cout << std::setw(10) << std::right << contacts[i].getFirstName() << '|';
		std::cout << std::setw(10) << std::right << contacts[i].getLastName() << '|';
		std::cout << std::setw(10) << std::right << contacts[i].getNickName() << '|';
		std::cout << std::endl;
	}	
	
	return (0);
}

std::string PhoneBook::askContactInfo(std::string info)
{
	std::string	Input;

	do {
		std::cout << "Enter " << info << ": ";
		std::getline(std::cin, Input);
		if (info == "phonenumber")
		{
			for(size_t i = 0; i < Input.length(); i++)
				if (!std::isdigit(Input[i]))
					Input.clear();
		}
		else
		{
			for(size_t i = 0; i < Input.length(); i++)
			{
				if (!std::isspace(Input[i]))
					break ;
				Input.clear();
			}
		}
	} while (Input.empty());
	return (Input);
}

int	PhoneBook::checkDigits(std::string str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (1);
	}
	return (0);
}