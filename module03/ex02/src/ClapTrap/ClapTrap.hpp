#ifndef CLAPTRAP_CPP
#define CLAPTRAP_CPP

#include <string>
#include <iostream>

class ClapTrap{
	protected:
		std::string	m_name;
		int			m_hp;
		int			m_energy;
		int			m_dmg;
	public:
		ClapTrap();
		ClapTrap( const std::string& name );
		ClapTrap( const ClapTrap& copy );
		ClapTrap&	operator=(const ClapTrap& other );
		~ClapTrap();

		void	attack( const std::string& target);
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif