#include <Cat.hpp>

Cat::Cat() : Animal(){
	m_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) : Animal(){
	m_type = copy.m_type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat&	Cat::operator=( const Cat& other ){
	if (this != &other){
		m_type = other.m_type;
	}
	return *this;
}

void	Cat::makeSound() const{
	std::cout << "Meow Meow Meooow" << std::endl;
}