#include <iostream>

class Vector2d {
 private:
  double x;
  double y;

 public:
  void SetX(double xArg) {
    x = xArg;
  }

  double GetX() {
    return x;
  }

  void SetY(double yArg) {
    y = yArg;
  }

  double GetY() {
    return y;
  }
};

int main() {
  Vector2d vec;

  /* Полю x объекта vec присваиваем значение 5. */
  vec.SetX(5);

  /* Выводим значение vec.x. */
  std::cout << "vec.x = " << vec.GetX() << std::endl;

  /* Ошибка компиляции. К приватным полям и методам класса могут обращаться только
     методы этого класса (почти). */
  // vec.x = 10;

  return 0;
}

