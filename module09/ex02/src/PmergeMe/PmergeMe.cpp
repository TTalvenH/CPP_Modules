#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <sys/time.h>

PmergeMe::PmergeMe(int argc, char** argv) : m_argv(argv)
{
	m_vec.reserve(argc - 1);
	for (int i = 0; i < argc; i++)
	{
		m_vec.push_back(std::atoi(argv[i]));
		m_list.push_back(std::atoi(argv[i]));
	}
}

PmergeMe::~PmergeMe(){}

#include <algorithm>

void PmergeMe::sort()
{
	struct timeval	start, end;
	long			seconds, microseconds, listTime, vecTime;

	std::cout << "Before: ";
	for (vectorIter it = m_vec.begin(); it != m_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	gettimeofday(&start, NULL);
	mergeInsertVec(0, m_vec.size() - 1, 20);
	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	vecTime = seconds * 1000000 + microseconds;

	gettimeofday(&start, NULL);
	m_list = mergeInsertList(m_list, 20);
	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	listTime = seconds * 1000000 + microseconds;

	std::cout << "After: ";
	for (listIter it = m_list.begin(); it != m_list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << m_vec.size() << " with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << m_list.size() << " with std::list : " << listTime << " us" << std::endl;

	// for (listIter it = m_list.begin(); it != m_list.end(); it++)
	// {
	// 	listIter next = it;
	// 	next++;
	// 	if (next != m_list.end() && *next < *it)
	// 	{
	// 		std::cout << "list not sorted" << std::endl;
	// 		break;
	// 	}
	// }
	// for (vectorIter it = m_vec.begin(); it != m_vec.end(); it++)
	// {
	// 	vectorIter next = it;
	// 	next++;
	// 	if (next != m_vec.end() && *next < *it)
	// 	{
	// 		std::cout << "vec not sorted" << std::endl;
	// 		break;
	// 	}
	// }
}

