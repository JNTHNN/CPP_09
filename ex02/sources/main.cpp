#include "../includes/PmergeMe.hpp"

//  num entier positifs

// 1er message : Before:    lasequenced'entiersnontries
// 2e message :  After:     lasequenced'entierstries
// 3e message :  Time to process a range of "nombred'entiers" elements with std::vector : 0.00031 us
// 4e message :  Time to process a range of "nombred'entiers" elements with std::deque : 0.00031 us

int main(int argc, char** argv)
{
    (void)argv; //  en "" et sans

    PmergeMe    vector;
    for (int i = 1; i < argc; ++i)
        vector.setVector(atoi(argv[i]));
    std::cout << "Before: ";
    vector.print();
    std::cout << std::endl;

    fordJohnson(vector);

    // return std::cerr << "Error" << std::endl, 1;
    return 0;
}

/*
    Jacobsthal:
    Jn = {  0    si n = 0;
            1    si n = 1;
            Jn - 1 + 2Jn - 2 si n >= 2; 
        };
*/