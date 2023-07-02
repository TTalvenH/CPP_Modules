#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <Contact.hpp>
# include <string>
# include <iostream>
# include <iomanip>
# include <limits>

class PhoneBook 
{
	private:
		Contact contacts[8];
		int			contactIndex;
		std::string	askContactInfo(std::string info);
		std::string createColumn(std::string, std::size_t columnSize);
		std::string truncIfNeeded(std::string str);
		int			checkDigits(std::string str);

	public:
		PhoneBook();
		int	addContact();
		int	search();
		~PhoneBook();
};

#endif
