#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain{

private:
	std::string	m_ideas[100];
public:
	Brain();
	Brain( const Brain& copy );
	Brain&	operator=( const Brain& other );
	~Brain();
	
	void		setIdea( const int index, const std::string idea );
	std::string	getIdea( const int index ) const;
};

#endif