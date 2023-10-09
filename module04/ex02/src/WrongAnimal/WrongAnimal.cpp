#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("WrongAnimal"){
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy ) : m_type(copy.m_type){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& other ){
	if (this != &other){
		m_type = other.m_type;
	}
	return *this;
}

void	WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string	WrongAnimal::getType() const{
	return m_type;
}