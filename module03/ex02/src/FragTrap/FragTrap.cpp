#include <FragTrap.hpp>

FragTrap::FragTrap() : ClapTrap(""){
	m_hp = 100;
	m_energy = 100;
	m_dmg = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap( const std::string& name ) : ClapTrap(name){
	m_hp = 100;
	m_energy = 100;
	m_dmg = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& copy ) : ClapTrap(copy.m_name){
	m_hp = copy.m_hp;
	m_energy = copy.m_energy;
	m_dmg = copy.m_dmg;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap deconstructor called" << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap& other ){
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other){
		m_name = other.m_name;
		m_hp = other.m_hp;
		m_energy = other.m_energy;
		m_dmg = other.m_dmg;
	}
	return *this;
}

void	FragTrap::attack( const std::string& target){
	if (m_energy > 0 && m_hp > 0){
		m_energy--;
		std::cout << "FragTrap " << m_name << " attacks " << target << ", causing " << m_dmg << " points of damage!" << std::endl;
	}
}

void	FragTrap::highFiveGuys( void ){
	std::cout << "CAN  I HAVE A HIGH FIVE GUYS!!!!!!!!!?" << std::endl;
}
