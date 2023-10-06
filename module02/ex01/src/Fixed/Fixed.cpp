#include "Fixed.hpp"

Fixed::Fixed() : m_fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy ){
	std::cout << "Copy constructor called" << std::endl;
	m_fixedPoint = copy.m_fixedPoint;
}

Fixed::Fixed( const int value ): m_fixedPoint(value << m_bits) { 
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value) : m_fixedPoint(static_cast<int>(roundf((value * (1 << m_bits))))){
	std::cout << "Float constructor called" << std::endl;
}

Fixed&	Fixed::operator=( const Fixed& copy ){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy){
		m_fixedPoint = copy.m_fixedPoint;
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor constructor called" << std::endl;
}

int		Fixed::getRawBits ( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return m_fixedPoint;
}

void	Fixed::setRawBits ( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	m_fixedPoint = raw;
}

float	Fixed::toFloat( void ) const{
	return static_cast<float>(m_fixedPoint) / (1 << m_bits);
}

int		Fixed::toInt( void ) const{
		return m_fixedPoint >> m_bits;
}

std::ostream&	operator<<( std::ostream& os, const Fixed& fixedPoint){
	return os << fixedPoint.toFloat();
}
