#ifndef PMERGEME_HPP
# define PMERGE_HPP

#include <iostream>
#include <algorithm>

class   PmergeMe
{
    private:
    // utilisation de std::vector + std::deque

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& copied);
        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& base);
};

#endif
