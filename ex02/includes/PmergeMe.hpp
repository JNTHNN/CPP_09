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

        std::vector<int>&   getVector();
        PmergeMe    setVector(int a);
        int         getVectorValue(size_t i);
        size_t      vectorSize() const;
        void        swap(size_t i, size_t j);
        void        remove(int i);

        void        print() const;

        const char* what() const throw();
};

void                    mergeSort(std::vector<int>& v, int left, int right);
void                    merge(std::vector<int>& v, int left, int mid, int right);
std::vector<size_t>     jacobsthal(size_t n);
void                    fordJohnson(PmergeMe& seq);
std::vector<int>        separate(PmergeMe& seq);
void                    insertSort(std::vector<int>& main, std::vector<int>& pending);
void                    pair(PmergeMe& seq);

#endif
