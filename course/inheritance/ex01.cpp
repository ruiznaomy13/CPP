#include <iostream>
using namespace std;

class Aminal
{
    public:
        void    eat() { cout << "I'm eating" << endl; }
        void    sleep() { cout << "I'm sleeping" << endl; }

};

class Dog : public Aminal
{
    public:
        void    talk() { cout << "WOOOOOF WOOOOOF" << endl; }
};

class Cat : public Aminal
{
    public:
        void    talk() { cout << "MIAUUUUU MIAAUUU" << endl; }
};

int main()
{
    Cat cat;
    Dog dog;

    cat.eat();
    dog.eat();
    dog.talk();
    cat.talk();
}