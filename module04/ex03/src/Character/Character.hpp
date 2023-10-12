#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../ICharacter/ICharacter.hpp"

#include <string>

class Character : public ICharacter{
private:
	std::string m_name;
	AMateria*	m_inventory[4];

public:
	Character();
	Character(const std::string& name);
	Character(const Character& copy);
	Character&	operator=(const Character& copy);
	~Character();

	std::string const&	getName() const;
	AMateria*			getItem(int idx) const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

};

#endif

