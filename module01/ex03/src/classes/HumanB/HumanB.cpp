#include <HumanB.hpp>

HumanB::HumanB( std::string name ) : m_name(name), m_weapon(NULL) {}

HumanB::~HumanB(){}

void	HumanB::attack(){
	std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon){
	m_weapon = &weapon;
}
