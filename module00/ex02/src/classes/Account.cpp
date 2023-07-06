#include <Account.hpp>
#include <ctime>
#include <iostream>

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_amount = initial_deposit;
}

Account::~Account()
{

}

void	Account::_displayTimestamp()
{
	std::time_t	currentTime = std::time(NULL);
	std::tm* 	localTime = std::localtime(&currentTime);
	std::cout << "[" << localTime->tm_year << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	
}

