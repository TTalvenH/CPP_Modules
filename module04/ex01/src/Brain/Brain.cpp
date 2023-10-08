#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain& copy ){
	for (int i = 0; i < 100; i++){
		m_ideas[i] = copy.m_ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain deconstructor called" << std::endl;
}

Brain&	Brain::operator=( const Brain& other ){
	if (this != &other){
		for (int i = 0; i < 100; i++){
			m_ideas[i] = other.m_ideas[i];
		}
	}
	return *this;
}

void	Brain::setIdea( const int index, const std::string idea ){
	if (index >= 0 && index <= 100){
		m_ideas[index] = idea;
	}
}
std::string	Brain::getIdea( const int index ) const{
	if (index >= 0 && index <= 100){
		return m_ideas[index];
	}
	return NULL;
}