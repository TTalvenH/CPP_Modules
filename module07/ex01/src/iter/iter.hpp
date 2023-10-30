#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename T, typename Func>
void iter(T array[], std::size_t length, Func function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void	printElem(const T& elem)
{
	std::cout << elem << std::endl;
}

#endif