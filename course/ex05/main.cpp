#include <iostream>

void	increment(int &value) //pass a variable to a ft_ as a reference
{
	value++;
}

/*
	pointer can be use exactly as a reference,
	but using reference are cleanest then not.
*/

int	main()
{
	int	a = 8;
	int	*b = &a;
	int	&c = a; //reference "variable", you have to inicialize it when declaring X&var;

	std::cout << a << " -> a in " << b << " = " << c << std::endl;

	// c = 10;
	while (c < 18)
		increment(c);

	std::cout << a << " -> a in " << b << " = " << c << std::endl;

	*b = 22;

	std::cout << a << " -> a in " << b << " = " << c << std::endl;
}
