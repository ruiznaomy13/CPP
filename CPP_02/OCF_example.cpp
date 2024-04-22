#include <iostream>

class Example {
private:
    int     data;
    size_t  size;

public:
    // Default constructor
    Example(int value = 0) : size(1), data(value) { }

    // Copy constructor
    Example(const Example& other) : size(1), data(other.data) {}

    // Copy assignment operator
    Example& operator=(const Example& other)
    {
        if (this != &other)
            data = other.data;
        return *this;
    }

    // Destructor
    ~Example() { }
};

int main() {
    Example ex1(5);
    Example ex2 = ex1; // Copy constructor called
    Example ex3;
    ex3 = ex1; // Copy assignment operator called
    return 0;
}
