#include "Rectangle.hpp"

Cercle::Cercle(int _radio)
{
  radio = _radio;
}

float Cercle::perimeter() {
  float result;

  result = 3.14 * (2*radio);
  return (result);
}

float Cercle::area() {
  float result;

  result = 3.14 * (radio * radio);
  return (result);
}
