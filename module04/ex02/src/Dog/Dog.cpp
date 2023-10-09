#include "Dog.hpp"

Dog::Dog() : Animal(){
	m_type = "Dog";
	m_brain = new Brain;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& copy ) : Animal(){
	m_brain = new Brain(*copy.m_brain);
	m_type = copy.m_type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
	delete m_brain;
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& other ){
	if (this != &other){
		delete m_brain;
		m_brain = new Brain(*other.m_brain);
		m_type = other.m_type;
	}
	return *this;
}

void	Dog::makeSound() const{
	std::cout << "Bark bark bark!" << std::endl;
}

Brain&	Dog::getBrain(){
	return *m_brain;
}