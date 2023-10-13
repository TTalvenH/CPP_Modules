#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "../ICharacter/ICharacter.hpp"

#include <string>

class ICharacter;

class AMateria{
protected:
	std::string	m_type;

public:
	AMateria();
	AMateria(std::string const& type);
	AMateria&	operator=(const AMateria& copy);
	virtual ~AMateria();
	std::string const&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void 		use(ICharacter& target) = 0;
};

#endif