#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal{

protected:
	std::string	m_type;

public:
	Animal();
	Animal( const Animal& copy );
	Animal&	operator=( const Animal& other );
	~Animal();

	virtual void	makeSound() const;
	std::string	getType() const;
};

#endif