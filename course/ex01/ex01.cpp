#include <iostream>

int	main()
{
	int	a;
	int	b;
	int	c;

	std::cout << "Introduce a number: ";
	std::cin >> a;
	std::cout << "Introduce other number: ";
	std::cin >> b;
	std::cout << "Which operation would you wanna do?\n1) +\n2) -\n3) /\n4) *\n";
	do
	{
		std::cin >> c;
		if (c == 1)
			std::cout << a << " + " << b << " = " << (a + b) << std::endl;
		else if (c == 2)
			std::cout << a << " - " << b << " = " << (a - b) << std::endl;
		else if (c == 3)
			std::cout << a << " / " << b << " = " << (a / b) << std::endl;
		else if (c == 4)
			std::cout << a << " * " << b << " = " << (a * b) << std::endl;
		else
			std::cout << "Not a valid operation, please choose:\na) +\nb) -\nc) /\nd) *\n";
	} while (c < 1 || c > 4);
	
	return (0);
}