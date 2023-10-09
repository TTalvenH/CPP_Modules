#include "Animal.hpp"

Animal::Animal() : m_type("Animal"){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( const Animal& copy ) : m_type(copy.m_type){
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal&	Animal::operator=( const Animal& other ){
	if (this != &other){
		m_type = other.m_type;
	}
	return *this;
}

void	Animal::makeSound() const{
	std::cout << "Animal makes sound" << std::endl;
}

std::string	Animal::getType() const{
	return m_type;
}