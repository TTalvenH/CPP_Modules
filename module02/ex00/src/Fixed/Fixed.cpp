#include "Fixed.hpp"

Fixed::Fixed() : m_fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy ){
	std::cout << "Copy constructor called" << std::endl;
	m_fixedPoint = copy.m_fixedPoint;
}

Fixed&	Fixed::operator=( const Fixed& copy ){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy){
		m_fixedPoint = copy.m_fixedPoint;
	}
	return (*this);
}

int		Fixed::getRawBits ( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return m_fixedPoint;
}

void	Fixed::setRawBits ( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	m_fixedPoint = raw;
}

Fixed::~Fixed(){
	std::cout << "Destructor constructor called" << std::endl;
}
