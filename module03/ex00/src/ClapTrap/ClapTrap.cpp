#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: m_name("")
	, m_hp(10)
	, m_energy(10)
	, m_dmg(0){
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string& name )
	: m_name(name)
	, m_hp(10)
	, m_energy(10)
	, m_dmg(0){
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& copy )
	: m_name(copy.m_name)
	, m_hp(copy.m_hp)
	, m_energy(copy.m_energy)
	, m_dmg(copy.m_dmg){
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Deconstructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& other ){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		m_name = other.m_name;
		m_hp = other.m_hp;
		m_energy = other.m_energy;
		m_dmg = other.m_dmg;
	}
	return *this;
}

void	ClapTrap::attack( const std::string& target){
	if (m_energy > 0 && m_hp > 0){
		m_energy--;
		std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_dmg << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ){
	m_hp -= amount;
	std::cout << "ClapTrap " << m_name << " takes " << amount << " damage!" << std::endl;
	if (m_hp < 0){
		m_hp = 0;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ){
	if (m_energy > 0 && m_hp > 0){
		m_energy--;
		m_hp += amount;
		std::cout << "ClapTrap " << m_name << " repairs " << amount << " of Hit Points!" << std::endl;
	}
}