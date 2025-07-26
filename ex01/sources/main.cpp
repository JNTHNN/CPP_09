#include "../includes/RPN.hpp"

// utilisation de std::stack
// tant que c'est un nombre, j'empile -> push()
// quand c'est un operateur, retirer 2 elements (verifier si la stack n'est pas vide empty())
// front() pour avoir acces au 1er element
// pop() pour remove le 1er elem

// faire en try catch pour throw error -> faire classe

int	main(int argc, char** argv)
{
	(void)argv;
	if (argc != 2)
		std::cerr << "Wrong argument : ./RPN \"0 1 +\"" << std::endl;
	
	RPN	calcul;
	int	i = 0;
	while (argv[1][i])
	{
		if (isdigit(argv[1][i]))
			calcul.stack(argv[1][i] - '0');
		else if (isOperator(argv[1][i]))
			calcul.destack(argv[1][i]);
		i++;
	}
	calcul.print();
}