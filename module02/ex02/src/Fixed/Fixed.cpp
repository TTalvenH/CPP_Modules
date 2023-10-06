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

Fixed::~Fixed(){
	std::cout << "Destructor constructor called" << std::endl;
}

Fixed&	Fixed::operator=( const Fixed& other ){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		m_fixedPoint = other.m_fixedPoint;
	}
	return (*this);
}

bool	Fixed::operator>( const Fixed& copy )const{
	return m_fixedPoint > copy.m_fixedPoint;
}

bool	Fixed::operator<( const Fixed& copy )const{
	return m_fixedPoint < copy.m_fixedPoint;
}

bool	Fixed::operator!=( const Fixed& copy )const{
	return m_fixedPoint != copy.m_fixedPoint;
}

bool	Fixed::operator>=( const Fixed& copy )const{
	return m_fixedPoint >= copy.m_fixedPoint;
}

bool	Fixed::operator<=( const Fixed& copy )const{
	return m_fixedPoint <= copy.m_fixedPoint;

}

bool	Fixed::operator==( const Fixed& other )const{
	return m_fixedPoint == other.m_fixedPoint;
}

Fixed	Fixed::operator+( const Fixed& other )const{
		Fixed result(m_fixedPoint + other.m_fixedPoint);
		return result;
}

Fixed	Fixed::operator-( const Fixed& other )const{
		Fixed result(m_fixedPoint - other.m_fixedPoint);
		return result;
}

Fixed	Fixed::operator*( const Fixed& other )const{
		Fixed result(0);
		result.m_fixedPoint = (m_fixedPoint * other.m_fixedPoint) >> m_bits;
		return result;
}

Fixed	Fixed::operator/( const Fixed& other )const{
		Fixed result((m_fixedPoint << m_bits) / other.m_bits);
		return result;
}

Fixed&	Fixed::operator++(){
		m_fixedPoint += 1;
		return *this;
}

Fixed	Fixed::operator++(int){
		Fixed temp(*this);
		m_fixedPoint += 1;
		return temp;
}

Fixed&	Fixed::operator--(){
		m_fixedPoint -= 1;
		return *this;
}

Fixed	Fixed::operator--(int){
		Fixed temp(*this);
		m_fixedPoint -= 1;
		return temp;
}

Fixed&	Fixed::min( Fixed& a, Fixed& b ){
	return (a > b ? b : a);
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b ){
	return (a > b ? b : a);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b ){
	return (a > b ? a : b);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b ){
	return (a > b ? a : b);
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
