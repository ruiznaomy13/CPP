#include <iostream>

class Fixed
{
	private:
		int value;

	public:
		Fixed(int v) : value(v) {}

		// Operador de suma no `const`
		Fixed operator+(const Fixed& other) {
			this->value += 1;  // Modifica el estado del objeto actual
			return Fixed(this->value + other.value);
		}

		// Operador de suma `const`
		Fixed operator+(const Fixed& other) const {
			return Fixed(this->value + other.value);  // No modifica el estado del objeto actual
		}

		int getValue() const {
			return value;
		}
};

int main()
{
	Fixed a(10);
	Fixed b(20);

	Fixed c = a + b;  // Usa el operador de suma

	std::cout << "c: " << c.getValue() << std::endl; 
	std::cout << "a: " << a.getValue() << std::endl;  // Debería ser 10 para la versión `const`, 11 para la versión no `const`
	std::cout << "b: " << b.getValue() << std::endl;  // Debería ser 20

	return 0;
}
