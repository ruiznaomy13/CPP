#include "Rectangle.hpp"

Rectangle::Rectangle(int _base, int _height)
{
  base = _base;
  height = _height;
}

int Rectangle::perimeter() {
  int result;

  result = (2*base) + (2*height);
  return (result);
}

int Rectangle::area() {
  int result;
    
  result = base * height;
  return (result);
}