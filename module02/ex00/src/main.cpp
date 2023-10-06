#include <Fixed.hpp>

int	main()
{	
	Fixed a;
	Fixed b( a );
	Fixed c;

	b.setRawBits(5);

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits()  << std::endl;

	c = a;
	std::cout << c.getRawBits()  << std::endl;

	return 0;
}
