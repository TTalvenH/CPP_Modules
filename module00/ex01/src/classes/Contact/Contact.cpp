#include "Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void	Contact::setFirstName(std::string input)
{
	firstName = input;
}

void	Contact::setLastName(std::string input)
{
	lastName = input;
}

void	Contact::setNickName(std::string input)
{
	nickName = input;
}

void	Contact::setPhoneNumber(std::string input)
{
	phoneNumber = input;
}

void	Contact::setDarkSecret(std::string input)
{
	darkSecret = input;
}

std::string	Contact::getFirstName()
{
	return (firstName);
}

std::string	Contact::getLastName()
{
	return (lastName);
}

std::string	Contact::getNickName()
{
	return (nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (phoneNumber);
}

std::string	Contact::getDarkSecret()
{
	return (darkSecret);
}

void	Contact::displayInformation()
{
	std::cout << "First name   : " << firstName << std::endl;
	std::cout << "Last name    : " << lastName << std::endl;
	std::cout << "Nickname     : " << nickName << std::endl;
	std::cout << "Phonenumber  : " << phoneNumber << std::endl;
	std::cout << "Dark secret  : " << darkSecret << std::endl;
}

bool	Contact::isEmpty()
{
	if (firstName.empty())
		return (true);
	return (false);
}