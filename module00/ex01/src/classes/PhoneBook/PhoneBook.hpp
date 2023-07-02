#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <Contact.hpp>
# include <string>
# include <iostream>
# include <iomanip>

class PhoneBook 
{
	private:
		Contact contacts[8];
		int		contactIndex;
		int		contactOldest;

		std::string	askContactInfo(std::string info);
		std::string createColumn(std::string, std::size_t columnSize);
		int			checkDigits(std::string str);
	public:
		PhoneBook();
		~PhoneBook();
		int	addContact();
		int	search();
};

#endif
