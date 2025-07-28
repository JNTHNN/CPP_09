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

void	RPN::run(char** arr)
{
	int	i = 0;
	while (arr[1][i])
	{
		if (isdigit(arr[1][i]))
			stack(arr[1][i] - '0');
		else if (isOperator(arr[1][i]))
			destack(arr[1][i]);
		i++;
	}
}


void	RPN::stack(int a)
{
	_rpn.push(a);
}

void	RPN::destack(char c)
{
	if (_rpn.size() < 2)
		throw Error();
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
		throw Error();
}

const char*	RPN::Error::what() const throw()
{
	return "Error";
}
