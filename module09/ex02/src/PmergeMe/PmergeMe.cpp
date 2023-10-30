#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>

PmergeMe::PmergeMe(int argc, char** argv) : m_argv(argv)
{
	m_vec.reserve(argc - 1);
	for (int i = 0; i < argc; i++)
	{
		m_vec.push_back(std::atoi(argv[i]));
		m_list.push_back(std::atoi(argv[i]));
	}
	for (unsigned int i = 0; i < m_vec.size(); i++)
	{
		std::cout << m_vec[i] << " ";
	}
	std::cout << std::endl;
	for (listIter it = m_list.begin(); it != m_list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
}

PmergeMe::~PmergeMe(){}

void PmergeMe::mergeVec(int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = 0;
	std::vector<int> temp(high - low + 1);

    while (i <= mid && j <= high)
	{
        if (m_vec[i] <= m_vec[j])
            temp[k++] = m_vec[i++];
        else
            temp[k++] = m_vec[j++];
    }
    while (i <= mid)
        temp[k++] = m_vec[i++];
    while (j <= high)
        temp[k++] = m_vec[j++];
    for (int x = 0; x < k; x++)
        m_vec[low + x] = temp[x];
}

void PmergeMe::mergeInsertVec(int low, int high, int threshold)
{
	if (low < high)
	{
		if (high - low <= threshold)
		{
			for (int i = low + 1; i <= high; i++)
			{
				int key = m_vec[i];
				int j = i - 1;
				while (j >= low && m_vec[j] > key)
				{
					m_vec[j + 1] = m_vec[j];
					j--;
				}
				m_vec[j + 1] = key;
			}
		}
		else
		{
			int mid = low + (high - low) / 2;
			mergeInsertVec(low, mid, threshold);
			mergeInsertVec(mid + 1, high, threshold);
			mergeVec(low, mid, high);
		}
	}
}

std::list<int> PmergeMe::mergeList(std::list<int>& left, std::list<int>& right)
{
    std::list<int> result;

    listIter leftIter = left.begin();
    listIter rightIter = right.begin();

    while (leftIter != left.end() && rightIter != right.end()) {
        if (*leftIter <= *rightIter) {
            result.push_back(*leftIter);
            ++leftIter;
        } else {
            result.push_back(*rightIter);
            ++rightIter;
        }
    }
    result.splice(result.end(), left);
    result.splice(result.end(), right);
    return result;
}

void PmergeMe::insertList(std::list<int>& lst)
{
    for (listIter it = ++lst.begin(); it != lst.end(); ++it)
	{
        int current = *it;
        listIter pos = it;
        while (pos != lst.begin() && *std::prev(pos) > current) {
            *pos = *std::prev(pos);
            --pos;
        }
        *pos = current;
    }
}

std::list<int> PmergeMe::mergeInsertList(std::list<int> lst, int threshold)
{
    if (m_list.size() <= static_cast<size_t>(threshold))
	{
        insertList(lst); 
		return lst;
	}
    else
	{
        int mid = m_list.size() / 2;
        std::list<int> left, right;

        listIter it = m_list.begin();
        for (int i = 0; i < mid; ++i)
		{
            left.push_back(*it);
            it = m_list.erase(it);
        }
        right = m_list;
        left = mergeInsertList(left, threshold);
        right = mergeInsertList(right, threshold);
        return mergeList(left, right);
    }
}

void PmergeMe::sort()
{
	mergeInsertVec(0, m_vec.size() - 1, 20);
	m_list = mergeInsertList(m_list, 20);
	for (unsigned int i = 0; i < m_vec.size(); i++)
	{
		std::cout << m_vec[i] << " "; 
	}
	 std::cout << std::endl;
	for (listIter it = m_list.begin(); it != m_list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

