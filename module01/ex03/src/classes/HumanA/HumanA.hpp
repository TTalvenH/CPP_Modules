#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "../Weapon/Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	private:
		std::string	m_name;
		Weapon&		m_weapon;

	public:
		HumanA( std::string name, Weapon& weapon);	
		void	attack();
		~HumanA();	
};

#endif