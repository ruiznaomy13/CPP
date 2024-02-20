#include <iostream>
#include <stdlib.h>

#include "Rectangle.hpp"

int main()
{
  Rectangle r1(5, 10);
  Cercle    c1(5);

  cout << "\n------ RECTANGLE ------ \nPerimeter: " << r1.perimeter() << "\nArea: " << r1.area() << endl;
  cout << "\n------- CERCLE -------- \nPerimeter: " << c1.perimeter() << "\nArea: " << c1.area() << endl;
  return 0;
}
