#include <iostream>

void	change_value(int **val1, int *val2)
{
	(void)val1;
	*val2 = 10;
}

int	main()
{
	int	var = 22;
	int	*ptr = &var;
	int	**var2 = &ptr; 
	std::cout << ptr << " in " << var2 << " " << var << std::endl;	

	// **var2 = 10;
	change_value(var2, ptr);
	
	std::cout << ptr << " in " << var2 << " " << var << std::endl;	
}
