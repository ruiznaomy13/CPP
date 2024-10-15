
#include <iostream>

class NonInstantiable
{
	private:
		NonInstantiable() {} // Constructor privado

	public:
		static void someStaticMethod() {
			std::cout << "Método estático." << std::endl;
		}
};

int main()
{
	// NonInstantiable obj; // Esto dará error, ya que el constructor es privado
	NonInstantiable::someStaticMethod(); // Esto es válido

	return 0;
}
