#include "../includes/PmergeMe.hpp"

std::vector<size_t> jacobsthal(size_t n)
{
	std::vector<size_t> numbers;
	size_t j0 = 0, j1 = 1;
	if (n == 0)
		return numbers;
	while (true)
	{
		size_t next = j1 + 2 * j0;
		if (next >= n)
			break;
		numbers.push_back(next);
		j0 = j1;
		j1 = next;
	}
	for (size_t i = 0; i < n; ++i) {
	    if (std::find(numbers.begin(), numbers.end(), i) == numbers.end())
	        numbers.push_back(i);
	}
	return numbers;
}

std::deque<size_t> jacobsthalD(size_t n)
{
	std::deque<size_t> numbers;
	size_t j0 = 0, j1 = 1;
	if (n == 0)
		return numbers;
	while (true)
	{
		size_t next = j1 + 2 * j0;
		if (next >= n)
			break;
		numbers.push_back(next);
		j0 = j1;
		j1 = next;
	}
	for (size_t i = 0; i < n; ++i) {
	    if (std::find(numbers.begin(), numbers.end(), i) == numbers.end())
	        numbers.push_back(i);
	}
	return numbers;
}
