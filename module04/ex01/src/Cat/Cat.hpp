#ifndef CAT_HPP
#define CAT_HPP

#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"

class Cat : public Animal {

private:
	Brain*	m_brain;

public:
	Cat();
	Cat( const Cat& copy );
	Cat&	operator=( const Cat& other );
	~Cat();

	void	makeSound() const;
		
};
#endif