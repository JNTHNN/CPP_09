#include "../includes/RPN.hpp"

static void	check_arg(int argc)
{
	if (argc != 2)
		throw RPN::Error();
}	

int	main(int argc, char** argv)
{
	try
	{
		check_arg(argc);
		RPN	calcul;
		calcul.run(argv);
		calcul.print();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
