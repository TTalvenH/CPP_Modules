#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal{

protected:
	std::string	m_type;

public:
	WrongAnimal();
	WrongAnimal( const WrongAnimal& copy );
	WrongAnimal&	operator=( const WrongAnimal& other );
	virtual ~WrongAnimal();

	void	makeSound() const; //edited virtual out so it functions wrong like pdf wants.
	std::string	getType() const;
};

#endif