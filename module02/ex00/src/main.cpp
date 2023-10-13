#include "./Fixed/Fixed.hpp"

int	main()
{	
	Fixed a;
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(10);

	std::cout << "\n========================\n" << std::endl;

	Fixed b( a );
	Fixed c;

	std::cout << "\n========================\n" << std::endl;

	c.setRawBits(20);

	std::cout << "\n========================\n" << std::endl;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits()  << std::endl;

	std::cout << "\n========================\n" << std::endl;

	c = a;
	std::cout << c.getRawBits()  << std::endl;

	std::cout << "\n========================\n" << std::endl;

	return 0;
}
