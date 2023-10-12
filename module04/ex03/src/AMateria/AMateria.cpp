#include "AMateria.hpp"

AMateria::AMateria() : m_type("none"){}

AMateria::AMateria(std::string const& type) : m_type(type){}

AMateria::~AMateria(){}

AMateria&	AMateria::operator=(const AMateria& copy){
	if (this != &copy){
	}
	return *this;
}

std::string const&	AMateria::getType() const{
	return m_type;
}
