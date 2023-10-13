#ifndef ICE_HPP
#define ICE_HPP

#include "../AMateria/AMateria.hpp"
#include <iostream>

class Ice : public AMateria{
public:
	Ice();
	~Ice();

	Ice*	clone() const;
	void	use(ICharacter& target);
};


#endif