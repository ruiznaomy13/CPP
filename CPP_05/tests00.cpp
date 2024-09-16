#include <iostream>
using namespace std;

float	divide(float f1, float f2)
{
	if (f2 == 0) {
		throw 15;
	} else {
		return (f1 / f2);
	}
}

int main ()
{
	float	f1;
	float	f2;

	cin >> f1;
	cin >> f2;

	try {
		cout << divide(f1, f2) << endl; 
	} catch (int e) { // got the exceptions and continue with the code
		cerr << "ERROR!" << endl;
	}
	cout << "I arrive here" << endl;

	cout << divide(f1, f2) << endl;
	cout << "I don't arrive here" << endl;
	return 0;
}