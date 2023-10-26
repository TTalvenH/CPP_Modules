#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span(unsigned int N) : m_size(N) {}

Span::Span(const Span& copy) : m_size(copy.m_size)
{
	m_data = copy.m_data;
}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{	
		m_size = copy.m_size;
		m_data = copy.m_data;
	}
	return *this;
}

Span::~Span(){}


void Span::addNumber(int number)
{
	if (m_data.size() >= m_size)
	{
		throw std::runtime_error("full!!!");\
	}
	m_data.push_back(number);
}

unsigned int Span::shortestSpan() const 
{
	if (m_data.size() < 2)
	{
		throw std::runtime_error("No span can be found!!!");
	}

	unsigned int shortestSpan = 0;
    for (size_t i = 0; i < m_data.size(); i++)
	{
        for (size_t j = i + 1; j < m_data.size(); j++)
		{
            unsigned int span = std::abs(m_data[i] - m_data[j]);
            if (!shortestSpan || span < shortestSpan)
                shortestSpan = span;
        }
    }
	return shortestSpan;
}
unsigned int Span::longestSpan() const 
{
	if (m_data.size() < 2)
	{
		throw std::runtime_error("No span can be found!!!");
	}
	std::vector<int>::const_iterator minIt = std::min_element(m_data.begin(), m_data.end());
	std::vector<int>::const_iterator maxIt = std::max_element(m_data.begin(), m_data.end());
	return *maxIt - *minIt;
}

#include <iostream>

void Span::fillSpan(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd)
{
	for (std::vector<int>::iterator it = itBegin; it != itEnd; it++)
		addNumber(*it);
}

std::vector<int>& Span::getData() { return m_data; }