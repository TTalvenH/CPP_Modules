#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{
private:
	T*		m_array;
	size_t	m_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array &);
	~Array();

	T& operator[](unsigned int index) const;
	unsigned int size() const;
};

#include "Array.tpp"

#endif