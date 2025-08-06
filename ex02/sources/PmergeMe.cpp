#include "../includes/PmergeMe.hpp"

static int	checkVal(std::string& nb)
{
	char* endptr = NULL;
	long val = std::strtol(nb.c_str(), &endptr, 10);
	if (*endptr != '\0' || val < INT_MIN || val > INT_MAX)
		return -1;
	else
		return val;
}

PmergeMe::PmergeMe(void)
{
	return;
}

PmergeMe::PmergeMe(int argc, char** argv)
{
	try
	{
		if (argc == 2)
		{
			std::istringstream	seq(argv[1]);
			std::string			token;
			while (seq >> token)
				setContainers(checkVal(token));
		}
		else if (argc > 2)
		{
			for (int i = 1; i < argc; ++i)
			{
				std::string	token(argv[i]);
				setContainers(checkVal(token));
			}
		}
		else
			throw Error();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

PmergeMe::PmergeMe(const PmergeMe& copied): _v(copied._v), _d(copied._d)
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
	{
		_v = base._v;
		_d = base._d;
	}
	return *this;
}

PmergeMe    PmergeMe::setContainers(int a)
{
	if (a >= 0)
	{
		_v.push_back(a);
		_d.push_back(a);
	}
	else
		throw Error();
	return *this;
}

int	PmergeMe::getVectorValue(size_t i)
{
	return _v[i];
}

std::vector<int>&	PmergeMe::getVector(void)
{
	return _v;
}

std::deque<int>&	PmergeMe::getDeque(void)
{
	return _d;
}

void   PmergeMe::print(void) const
{
	for (size_t i = 0; i < _v.size(); ++i)
		std::cout << _v[i] << " ";
	std::cout << std::endl;
}

const char*	PmergeMe::Error::what(void) const throw()
{
	return "Error";
}

bool	PmergeMe::isSorted() const
{
    for (size_t i = 1; i < _v.size(); ++i)
        if (_v[i - 1] > _v[i])
            return false;
    return true;
}

size_t	PmergeMe::getVectorSize(void) const
{
	return _v.size();
}

size_t	PmergeMe::getDequeSize(void) const
{
	return _d.size();
}