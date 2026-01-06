#include <cmath>
// Для использования класса необходимо подключить заголовочный файл с его объявлением.
#include "vector2d.hpp"

/* Для того, чтобы сказать компилятору о том, что мы пишем реализацию метода
   класса Vector2d, а не отдельную функцию, необходимо написать Vector2d:: перед
   названием каждого метода. */
Vector2d::Vector2d() :
  x(0),
  y(0)
{ }

Vector2d::Vector2d(double xArg, double yArg) :
  x(xArg),
  y(yArg)
{ }

double Vector2d::Length() const {
  return std::sqrt(x * x + y * y);
}

void Vector2d::Add(const Vector2d& other) {
  x += other.x;
  y += other.y;
}

