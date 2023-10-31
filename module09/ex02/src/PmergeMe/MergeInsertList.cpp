#include "PmergeMe.hpp"

std::list<int> PmergeMe::mergeList(std::list<int>& left, std::list<int>& right)
{
    std::list<int> result;

    listIter leftIter = left.begin();
    listIter rightIter = right.begin();

    while (leftIter != left.end() && rightIter != right.end())
    {
        if (*leftIter <= *rightIter)
        {
            result.push_back(*leftIter);
            ++leftIter;
        }
        else
        {
            result.push_back(*rightIter);
            ++rightIter;
        }
    }
    while (leftIter != left.end())
    {
        result.push_back(*leftIter);
        ++leftIter;
    }
    while (rightIter != right.end())
    {
        result.push_back(*rightIter);
        ++rightIter;
    }

    return result;
}

void PmergeMe::insertList(std::list<int>& lst)
{
    for (listIter it = lst.begin(); it != lst.end(); ++it)
    {
        int current = *it;
        listIter pos = it;
        while (pos != lst.begin())
        {
            listIter prevPos = pos;
            --prevPos;
            if (*prevPos > current)
            {
                *pos = *prevPos;
                --pos;
            }
            else
            {
                break;
			}
        }
        *pos = current;
    }
}

std::list<int> PmergeMe::mergeInsertList(std::list<int> lst, int threshold)
{
    if (lst.size() <= static_cast<size_t>(threshold))
	{
        insertList(lst); 
		return lst;
	}
    else
	{
        int mid = lst.size() / 2;
        std::list<int> left, right;

        listIter it = lst.begin();
        for (int i = 0; i < mid; ++i)
		{
            left.push_back(*it);
            it = lst.erase(it);
        }
        right = lst;
        left = mergeInsertList(left, threshold);
        right = mergeInsertList(right, threshold);
        return mergeList(left, right);
    }
}