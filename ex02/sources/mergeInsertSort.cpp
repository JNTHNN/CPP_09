#include "../includes/PmergeMe.hpp"

void	merge(std::vector<int>& v, int left, int mid, int right)
{
	std::vector<int> temp;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (v[i] < v[j])
			temp.push_back(v[i++]);
		else
			temp.push_back(v[j++]);
	}
	while (i <= mid)
		temp.push_back(v[i++]);
	while (j <= right)
		temp.push_back(v[j++]);
	for (int k = 0; k < (int)temp.size(); ++k)
		v[left + k] = temp[k];
}

void	mergeSort(std::vector<int>& v, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(v, left, mid);
		mergeSort(v, mid + 1, right);
		merge(v, left, mid, right);
	}
}


void	insertSort(std::vector<int>& main, std::vector<int>& pending)
{
	std::vector<size_t>	order = jacobsthal(pending.size());
	// std::cout << "\njacobsthal: ";
	// for (std::vector<size_t>::iterator i = order.begin(); i != order.end(); ++i)
	// {
	// 	std::cout << *i << " ";
	// }
	for (size_t k = 0; k < order.size(); ++k)
	{
		int val = pending[order[k]];
		std::vector<int>::iterator pos = std::upper_bound(main.begin(), main.end(), val);
		main.insert(pos, val);
	}
}