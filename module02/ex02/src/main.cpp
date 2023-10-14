#include "./Fixed/Fixed.hpp"

int	main()
{	
	{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
	std::cout << "\n=================================\n" << std::endl;
	Fixed a = Fixed( 5 );
	Fixed b = Fixed( 3 );

	std::cout << a << " > " << b << " = " <<  (a > b) << std::endl;
	std::cout << a << " < " << b << " = " <<  (a < b) << std::endl;
	std::cout << a << " >= " << b << " = " << (a >= b) << std::endl;
	std::cout << a << " <= " << b << " = " << (a <= b) << std::endl;
	std::cout << a << " == " << b << " = " << (a == b) << std::endl;
	std::cout << a << " != " << b << " = " << (a != b) << std::endl;

	std::cout << "\n=================================\n" << std::endl;

	Fixed plus		(a + b);
	Fixed minus		(a - b);
	Fixed multibly	(a * b);
	Fixed divide	(a / b);
	std::cout << a << " + " << b << " = " << plus << std::endl;
	std::cout << a << " - " << b << " = " << minus << std::endl;
	std::cout << a << " * " << b << " = " << multibly << std::endl;
	std::cout << a << " / " << b << " = " << divide << std::endl;
	
	std::cout << "\n=================================\n" << std::endl;

	std::cout << a << " after pre-increment++ :" << a++ << std::endl;
	std::cout << a << " after post-increment++: " << ++a << " -> " << a << std::endl;

	std::cout << "\n=================================\n" << std::endl;

	std::cout << a << " after pre-decrement-- :" << a-- << std::endl;
	std::cout << a << " after post-decrement--: " << --a << " -> " << a << std::endl;

	std::cout << "\n=================================\n" << std::endl;

	Fixed const const_a = Fixed(6);
	Fixed const const_b = Fixed(5);

	std::cout << "min( " << const_a << ", " << const_b << " ); = " << Fixed::min(const_a, const_b) << std::endl;
	std::cout << "max( " << const_a << ", " << const_b << " ); = " << Fixed::max(const_a, const_b) << std::endl;
	}
	return 0;
}
