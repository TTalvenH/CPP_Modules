#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	m_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& copy ) : WrongAnimal(){
	m_type = copy.m_type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& other ){
	if (this != &other){
		m_type = other.m_type;
	}
	return *this;
}

void	WrongCat::makeSound() const{
	std::cout << "WrongCat sounds woeM woeM woeM" << std::endl;
}