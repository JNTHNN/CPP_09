#include "../includes/PmergeMe.hpp"

static void	insertSort(std::deque<int>& main, std::deque<int>& pending, int& odd)
{
	std::deque<size_t>	order = jacobsthalD(pending.size());
	for (size_t k = 0; k < order.size(); ++k)
	{
		int val = pending[order[k]];
		std::deque<int>::iterator pos = std::upper_bound(main.begin(), main.end(), val);
		main.insert(pos, val);
	}
	if (odd != -1)
    {
        std::deque<int>::iterator pos = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(pos, odd);
    }
}

static void	separate(std::deque<std::pair<int, int> >& pairs, std::deque<int>& main, std::deque<int>& pending)
{
    for (size_t j = 0; j < pairs.size(); ++j)
	{
		main.push_back(pairs[j].second);
        pending.push_back(pairs[j].first);
    }
}

static void pair(const std::deque<int>& seq, std::deque<std::pair<int, int> >& pairs, int& odd)
{
    size_t i = 0;
    for (; i + 1 < seq.size(); i += 2)
        pairs.push_back(std::make_pair(std::min(seq[i], seq[i+1]), std::max(seq[i], seq[i+1])));
    odd = (i < seq.size()) ? seq[i] : -1;
}

void fordJohnson(std::deque<int>& seq)
{
    if (seq.size() <= 1)
	return;

    std::deque<std::pair<int, int> > pairs;
    std::deque<int> main, pending;
	int	odd;

	pair(seq, pairs, odd);
	separate(pairs, main, pending);	
    fordJohnson(main);
	insertSort(main, pending, odd);
    seq = main;
}
