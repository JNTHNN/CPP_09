#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <climits>
#include <ctime>

class   PmergeMe
{
    private:
    // utilisation de std::vector + std::deque
    std::vector<int>    _v;
    std::deque<int>     _d;

    public:
        PmergeMe();
        PmergeMe(int argc, char** argv);
        PmergeMe(const PmergeMe& copied);
        ~PmergeMe();

        PmergeMe&           operator=(const PmergeMe& base);

        std::vector<int>&   getVector();
        std::deque<int>&    getDeque();
        PmergeMe            setContainers(int a);
        int                 getVectorValue(size_t i);
        size_t              getVectorSize() const;
        size_t              getDequeSize() const;

        void                print() const;
        bool                isSorted() const;

        class   Error: public std::exception
        {
            const char* what() const throw();
        };
};

std::vector<size_t>     jacobsthal(size_t n);
std::deque<size_t>      jacobsthalD(size_t n);
void                    fordJohnson(std::vector<int>& seq);
void                    fordJohnson(std::deque<int>& seq);

#endif
