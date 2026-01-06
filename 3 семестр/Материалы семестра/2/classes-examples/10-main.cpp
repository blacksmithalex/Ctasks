#include <iostream>
#include "vector2d.hpp"

int main() {
  Vector2d vec(3, 4);
  Vector2d anotherVec(10, 5);

  vec.Add(anotherVec);

  /* Выведет 13 и 9. */
  std::cout << "vec.x = " << vec.X()
            << "vec.y = " << vec.Y() << std::endl; 
  return 0;
}

