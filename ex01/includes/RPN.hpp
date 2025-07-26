#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>

class   RPN
{
    private:
        std::stack<int>	_rpn;

    public:
        RPN();
        RPN(const RPN& copied);
        ~RPN();

        RPN& operator=(const RPN& base);

		void	stack(int a);
		void	destack(char c);
		void	print() const;

};

bool	isOperator(char c);

#endif
