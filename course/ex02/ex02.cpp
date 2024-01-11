#include <iostream>
#include <string.h>
using namespace std;

// Functions
class	NaoClass
{
	public:
		void favFood() {
			cout << "RAMEN !!\n";
		}
};

int	main()
{
	NaoClass nao;

	nao.favFood();
	return (0);
}