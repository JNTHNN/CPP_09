#include "RPN.hpp"

RPN::RPN(void)
{
	return;
}

RPN::RPN(const RPN& copied): _rpn(copied._rpn)
{
	return;
}

RPN::~RPN(void)
{
	return;
}

RPN&	RPN::operator=(const RPN& base)
{
	if (this != &base)
		_rpn = base._rpn;
	return *this;
}

void	RPN::stack(int a)
{
	_rpn.push(a);
}

void	RPN::destack(char c)
{
	if (_rpn.size() < 2)
		std::cerr << "error: stack not enough fill" << std::endl;
	else
	{
		int	b = _rpn.top();
		_rpn.pop();
		int	a = _rpn.top();
		_rpn.pop();

		switch (c)
		{
			case '+':
				_rpn.push(a + b);
				break;
			case '-':
				_rpn.push(a - b);
				break;
			case '/':
				if (b == 0)
				{
					std::cerr << "Not a Number" << std::endl;
					break;
				}
				_rpn.push(a / b);
				break;
			case '*':
				_rpn.push(a * b);
				break;
		}
	}

}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::print(void) const
{
	if (_rpn.size() == 1)
		std::cout << _rpn.top() << std::endl;
	else
		std::cerr << "error: stack more than one result" << std::endl;
}