#include <iostream>
#include <stdlib.h>

using namespace std;

class Person {
  private: // Atributes
    int     age;
    string  name;

  public: // Methods
    Person(int,string); //constructor
    void  read();
    void  run();
};

// Constructor: inicializar los atributos de la clase
Person::Person(int _age, string _name)
{
  age = _age;
  name = _name;
}

//Metodos
void  Person::read() {
  cout << "Soy " << name << " estoy leyendo." << endl;
}

void  Person::run() {
  cout << "Soy " << name << " estoy corriendo." << endl;
}

int main() {
  
  Person p1 = Person(22, "Naomy");
  Person p2(31, "Pepito");

  p1.run();
  p2.read();

  return 0;
}
