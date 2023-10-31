#include "PmergeMe.hpp"

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
