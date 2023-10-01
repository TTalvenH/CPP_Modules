#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
{	
	contactIndex = 0;
}

PhoneBook::~PhoneBook()
{	
}

int	PhoneBook::addContact()
{
	if (contactIndex == 8)
		contactIndex = 0;
	contacts[contactIndex].setFirstName(askContactInfo("first name"));
	contacts[contactIndex].setLastName(askContactInfo("last name"));
	contacts[contactIndex].setNickName(askContactInfo("nickname"));
	contacts[contactIndex].setPhoneNumber(askContactInfo("phonenumber"));
	contacts[contactIndex].setDarkSecret(askContactInfo("dark secret"));
	contactIndex++;
	return (0);
}

int PhoneBook::search()
{
	int			input;
	int			indexCount = 0;

	for (size_t i = 0; i < 8; i++)
	{
		if (contacts[i].isEmpty())
			continue ;
		std::cout << std::setw(10) << std::right << i << '|';
		std::cout << std::setw(10) << std::right << truncIfNeeded(contacts[i].getFirstName()) << '|';
		std::cout << std::setw(10) << std::right << truncIfNeeded(contacts[i].getLastName()) << '|';
		std::cout << std::setw(10) << std::right << truncIfNeeded(contacts[i].getNickName()) << '|';
		std::cout << std::endl;
		indexCount++;
	}
	if (indexCount)
	{
		std::cout << "Give index: ";
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			input = -1;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input < indexCount && input >= 0)
			contacts[input].displayInformation();
		else
			std::cout << "Index not found" << std::endl;
	}
	return (0);
}

std::string PhoneBook::askContactInfo(std::string info)
{
	std::string	Input;

	do {
		std::cout << "Enter " << info << ": ";
		std::getline(std::cin, Input);
		if (std::cin.eof() || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            exit(0);
        }
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

std::string	PhoneBook::truncIfNeeded(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
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
