#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>

class   RPN
{
    private:
        //utilisation std::queue
    public:
        RPN();
        RPN(const RPN& copied);
        ~RPN();

        RPN& operator=(const RPN& base);

};

#endif
