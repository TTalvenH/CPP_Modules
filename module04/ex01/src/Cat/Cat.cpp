#include "Cat.hpp"

Cat::Cat() : Animal(){
	m_type = "Cat";
	m_brain = new Brain;
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) : Animal(){
	m_brain = new Brain(*copy.m_brain);
	m_type = copy.m_type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(){
	delete m_brain;
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat&	Cat::operator=( const Cat& other ){
	if (this != &other){
		delete m_brain;
		m_brain = new Brain(*other.m_brain);
		m_type = other.m_type;
	}
	return *this;
}

void	Cat::makeSound() const{
	std::cout << "Meow Meow Meooow" << std::endl;
}