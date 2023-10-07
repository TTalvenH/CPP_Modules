#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap(""){
	m_hp = 100;
	m_energy = 50;
	m_dmg = 20;
	std::cout << "Scavtrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name){
	m_hp = 100;
	m_energy = 50;
	m_dmg = 20;
	std::cout << "Scavtrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& copy ) : ClapTrap(copy.m_name){
	m_hp = copy.m_hp;
	m_energy = copy.m_energy;
	m_dmg = copy.m_dmg;
	std::cout << "Scavtrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "Scavtrap deconstructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& other ){
	std::cout << "Scavtrap copy assignment operator called" << std::endl;
	if (this != &other){
		m_name = other.m_name;
		m_hp = other.m_hp;
		m_energy = other.m_energy;
		m_dmg = other.m_dmg;
	}
	return *this;
}

void	ScavTrap::attack( const std::string& target){
	if (m_energy > 0 && m_hp > 0){
		m_energy--;
		std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_dmg << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate(){
	std::cout << " is in Gate keeper mode!" << std::endl;
}
