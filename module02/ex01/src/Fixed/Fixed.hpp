#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int					m_fixedPoint;
		static const int	m_bits = 8;

	public:
		Fixed();
		Fixed( const Fixed& copy );
		Fixed( const int value);
		Fixed( const float value);
		Fixed&	operator=( const Fixed& copy);
		~Fixed();

		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream&	operator<<( std::ostream& os, const Fixed& fixedPoint);

#endif