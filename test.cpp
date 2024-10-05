
#include <iostream>
using namespace std;
class Example {
    private:
        int _n1, _n2; 
    public:
        Example(int n1, int n2) : _n1(n2), _n2(n2) {}
        Example operator+(Example const& obj) {
            Example res(0, 0);
            res._n1 = _n1 + obj._n1;
            res._n2 = _n2 + obj._n2;
            return (res);
        }
        void print() { cout << _n1 << " + i" << _n2 << '\n'; }
};
        
int main()
{
    Example c1(10, 5), c2(2, 4);
    Example c3 = c1 + c2;
    c3.print();
}