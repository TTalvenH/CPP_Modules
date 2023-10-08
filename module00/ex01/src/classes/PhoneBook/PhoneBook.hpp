#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "../Contact/Contact.hpp"

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdlib>

class PhoneBook 
{
	private:
		Contact 	contacts[8];
		int			contactIndex;

		int			checkDigits(std::string str);
		std::string	askContactInfo(std::string info);
		std::string truncIfNeeded(std::string str);

	public:
		PhoneBook();
		int	addContact();
		int	search();
		~PhoneBook();
};

#endif
