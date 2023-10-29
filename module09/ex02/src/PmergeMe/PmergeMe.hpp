#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>

class PmergeMe
{
private:
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);

public:
	PmergeMe();
	~PmergeMe();

};

#endif