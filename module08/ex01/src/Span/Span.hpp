#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
	std::vector<int>	m_data;
	unsigned int		m_size;

	Span();
	
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span &);
	~Span();

	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	void fillSpan(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd);
	std::vector<int>& getData();
};

#endif