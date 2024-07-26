#include <iostream>

/*
	----------------------------- I N H E R I T A N C E -----------------------------------
	It inherits the features/properties/characteristics of Base class into Derived class.
	Code reusability
	
	# TYPE:
	- SINGLE: A derived class with only one base class.
	- MULTILEVEL: A derived class with a base class and that base class is a derived class of another.
	- MULTIPLE: A derived class with multiple base class.
	- HERARCHICAL: Multiple derived classes with same base class.
	- MULTIPATH: A derived class with two base classes and these two base classes have one common base class.

	# MODES:
	PUBLIC: Visible to everyone
	PROTECTED: Visible to current class and derived class only
	PRIVATE: Visible to current class only
	________________________________________________________________________________
	BASE CLASS  |	Derived PUBLIC	|	Derived PRIVATE		|	Derived Protected	| <<<--- Inheritance Modes
	____________|___________________|_______________________|_______________________|
				|					|						|						|
	PRIVATED	|	Not inheritance	|	Not inheritance		|	Not inheritance		|
	------------|-------------------|-----------------------|-----------------------|
	PROTECTED	|	Protected		|	Private				|	Protected			|
	------------|-------------------|-----------------------|-----------------------|
	PUBLIC		|	Public			|	Private				|	Protected			|
	------------|-------------------|-----------------------|-----------------------|
*/

using namespace std;

class Base
{
	protected:
		int	x;
};


class Derived : public Base
{
	public:
		void	print() { cout << x << endl; }
};


int main()
{
	// Base	B1;
	Derived	B2;

	// B1.x = 10;
	// B2.x = 5;
	B2.print();
	// std::cout << B1.x << std::endl;
	// std::cout << B2.x << std::endl;

	return 0;
}
