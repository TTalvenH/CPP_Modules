#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../ClapTrap/ClapTrap.hpp"

class FragTrap : public ClapTrap{
	private:

	public:
		FragTrap();
		FragTrap( const std::string& name );
		FragTrap( const FragTrap& copy );
		~FragTrap();
		FragTrap&	operator=( const FragTrap& other );
		void	attack( const std::string& target );
		void	highFiveGuys( void );
};

#endif