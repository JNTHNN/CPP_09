#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class   PmergeMe
{
    private:
    // utilisation de std::vector + std::deque
    std::vector<int>    _v;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& copied);
        ~PmergeMe();

        PmergeMe&   operator=(const PmergeMe& base);

        PmergeMe    setVector(int a);

        void        print() const;
        void        pairFormation();
};


#endif
