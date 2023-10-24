#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <iostream>

template <typename T>
class Array
{
private:

public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array &);
	~Array();
};

#endif