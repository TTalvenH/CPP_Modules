#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <sstream>

class	Contact
{
	private:
		std::string	firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkSecret;

	public:
		Contact();
		void setFirstName(std::string input);
		void setLastName(std::string input);
		void setNickName(std::string input);
		void setPhoneNumber(std::string input);
		void setDarkSecret(std::string input);
		void displayInformation();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkSecret();
		bool isEmpty();
		~Contact();

};
#endif