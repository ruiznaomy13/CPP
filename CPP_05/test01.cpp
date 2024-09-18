#include <iostream>

/* EXCEPTIONS */
// without argument
class MyException : public std::exception {
    public:
        const char *what() {
            return ("MyEXception was thrown");
        }
};

// with argument
class MyException2 : public std::exception {
    private:
        std::string message = "MyException2: ";

    public:
        MyException2(const std::string &msg = "") {
            this->message += msg;
        }
        const char  *what() {
            return (this->message).c_str();
        }
};

void    funct1() {
    throw MyException();
}

void    funct2() {
    throw MyException2("Hello Exception");
}

int main( void )
{
    try
    {
        funct1();
    }
    catch(MyException &ex)
    {
        std::cout << "Function 1 - "  << ex.what() << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    
    try
    {
        funct2();
    }
    catch(MyException2 &ex)
    {
        std::cout << "Function 2 - "  << ex.what() << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
}