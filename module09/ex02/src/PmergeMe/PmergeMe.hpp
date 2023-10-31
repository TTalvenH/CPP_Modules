#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <list>

class PmergeMe
{

typedef std::vector<int>::iterator vectorIter;
typedef std::list<int>::iterator listIter;

private:
	std::vector<int>	m_vec;
	std::list<int>		m_list;
	char**				m_argv;

	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);

	void 			mergeInsertVec(int low, int high, int threshold);
	std::list<int> 	mergeInsertList(std::list<int> lst, int threshold);
	void 			mergeVec(int low, int mid, int high);
	std::list<int> 	mergeList(std::list<int>& left, std::list<int>& right);
	void 			insertList(std::list<int>& lst);
	void			validInput() const;
public:
	PmergeMe(int argc, char* argv[]);
	~PmergeMe();

	void sort();
};

#endif