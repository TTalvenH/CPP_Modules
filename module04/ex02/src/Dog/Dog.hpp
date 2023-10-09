#ifndef DOG_HPP
#define DOG_HPP

#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"

class Dog : public Animal {

private:
	Brain*	m_brain;

public:

	Dog();
	Dog( const Dog& copy );
	Dog&	operator=( const Dog& other );
	~Dog();

	void	makeSound() const;
	Brain&	getBrain();

};

#endif