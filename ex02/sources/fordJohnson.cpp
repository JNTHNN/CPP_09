#include "../includes/PmergeMe.hpp"

std::vector<int>    separate(PmergeMe& seq)
{
    std::vector<int>    pending;
    int	start = (seq.vectorSize() % 2 == 0) ? 0 : 1;
    for (int i = seq.vectorSize() - 2; i >= start; i -= 2)
    {
        if (seq.getVectorValue(i) < seq.getVectorValue(i + 1))
        {
            pending.push_back(seq.getVectorValue(i));
            seq.remove(i);
        }
        else
        {
            pending.push_back(seq.getVectorValue(i + 1));
            seq.remove(i + 1);
        }
    }
    return pending;
}

void    pair(PmergeMe& seq)
{
	for (size_t i = 0; i + 1 < seq.vectorSize(); i += 2)
	{
		if (seq.getVectorValue(i) > seq.getVectorValue(i + 1))
			seq.swap(i, i + 1);
	}
}

void    fordJohnson(PmergeMe& seq)
{
    pair(seq);
    // std::cout << "Pair Formation: ";
    // seq.print();
    // std::cout << std::endl;

    std::vector<int>    pending = separate(seq);
	
    // std::cout << "Main before: ";
    // seq.print();
    mergeSort(seq.getVector(), 0, seq.vectorSize() - 1);
    // std::cout << "\nMain after: ";
    // seq.print();
    // std::cout << "\nPending: ";
	// for (std::vector<int>::iterator i = pending.begin(); i != pending.end(); ++i)
	// {
	// 	std::cout << *i << " ";
	// }
    insertSort(seq.getVector(), pending);
	std::cout << "\nAfter : ";
	seq.print();
}
