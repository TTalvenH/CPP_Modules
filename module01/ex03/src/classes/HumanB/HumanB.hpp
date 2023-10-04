#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <Weapon.hpp>
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string	m_name;
		Weapon*		m_weapon;

	public:
		HumanB( std::string name );	
		void	setWeapon(Weapon& weapon);
		void	attack();
		~HumanB();	
};

#endif