#include "Character.hpp"

Character::Character() : m_name(""){
	for (int i = 0; i < 4; i++){
		m_inventory[i] = NULL;
	}
}

Character::Character(const std::string& name) : m_name(name) {}

Character::Character(const Character& copy) : m_name(copy.m_name){
	for (int i = 0; i < 4; i++){
		m_inventory[i] = copy.m_inventory[i];
	}
}

Character&	Character::operator=(const Character& copy){
	if (this != &copy){
		m_name = copy.m_name;
		for (int i = 0; i < 4; i++){
			delete m_inventory[i]; 
			m_inventory[i] = copy.m_inventory[i];
		}
	}
	return *this;
}

Character::~Character() {}

std::string const&	Character::getName() const{return m_name;}

void	Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++){
		if (!m_inventory[i]){
			m_inventory[i] = m;
			break;
		}
	}
}

AMateria*	Character::getItem(int idx) const{
	if (idx >= 0 && idx <= 3){
		return m_inventory[idx];
	}
	return NULL;
}

void	Character::unequip(int idx){
		if (idx >= 0 && idx <= 3){
			m_inventory[idx] = NULL;
		}
}

void	Character::use(int idx, ICharacter& target){
	if ((idx >= 0 && idx <= 3) && m_inventory[idx]){
		m_inventory[idx]->use(target);
	}
}
