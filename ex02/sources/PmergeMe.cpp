#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    return;
}

PmergeMe::PmergeMe(const PmergeMe& copied): _v(copied._v)
{
    return;
}

PmergeMe::~PmergeMe(void)
{
    return;
}

PmergeMe&   PmergeMe::operator=(const PmergeMe& base)
{
    if (this != &base)
        _v = base._v;
    return *this;
}

PmergeMe    PmergeMe::setVector(int a)
{
    if (a >= 0)
        _v.push_back(a);
    else
        std::cerr << "Error" << std::endl;
    return *this;
}

void   PmergeMe::print(void) const
{
    for (size_t i = 0; i < _v.size(); ++i)
        std::cout << _v[i] << " ";
}

void    PmergeMe::pairFormation(void)
{
    for (size_t i = 0; i + 1 < _v.size(); i += 2)
    {
        if (_v[i] > _v[i + 1])
            std::swap(_v[i], _v[i + 1]);
    }
}