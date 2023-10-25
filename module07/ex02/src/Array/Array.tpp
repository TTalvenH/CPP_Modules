#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : m_array(NULL), m_size(0) {}

template <typename T>
Array<T>::~Array(){ delete[] m_array; }

template <typename T>
Array<T>::Array(unsigned int n) : m_array(new T[n]), m_size(n) {}

template <typename T>
Array<T>::Array(const Array& copy) : m_array(new T[copy.m_size]), m_size(copy.m_size)
{
	for (unsigned int i = 0; i < m_size; i++)
	{
		m_array[i] = copy.m_array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		delete[] m_array;
		m_size = copy.m_size;
		m_array = new T[m_size];
		for (unsigned int i = 0; i < m_size; i++)
			m_array[i] = copy.m_array[i];
	}
	return(*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index >= m_size)
		throw std::exception();
	return m_array[index];
}

template <typename T>
unsigned int Array<T>::size() const { return m_size; }