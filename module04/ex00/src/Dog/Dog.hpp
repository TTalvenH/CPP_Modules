#ifndef DOG_HPP
#define DOG_HPP

#include "../Animal/Animal.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog( const Dog& copy );
		Dog&	operator=( const Dog& other );
		~Dog();

		void	makeSound() const;
	
};

#endif