#include <Dog.hpp>

Dog::Dog() :  Animal() {
	m_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& copy ) : Animal(){
	m_type = copy.m_type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& other ){
	if (this != &other){
		m_type = other.m_type;
	}
	return *this;
}

void	Dog::makeSound() const{
	std::cout << "Bark bark bark!" << std::endl;
}