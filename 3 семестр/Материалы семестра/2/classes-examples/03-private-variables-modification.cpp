#include <iostream>

class Vector2d {
 private:
  double x;
  double y;
 public:
  /* Метод AddMeToAnotherVector() прибавляет к своему аргументу объект, у которого
     он вызван. Аргумент передаётся по ссылке, поэтому он снаружи поменяется. */
  void AddMeToAnotherVector(Vector2d& other) {
    other.x += x;
    other.y += y;
  }

  void SetX(double xArg) { x = xArg; }
  double GetX() { return x; }
  void SetY(double yArg) { y = yArg; }
  double GetY() { return y; }
};

int main() {
  Vector2d vec1;
  Vector2d vec2;

  /* Задаём первый вектор. */
  vec1.SetX(1);
  vec1.SetY(2);

  /* Задаём второй вектор. */
  vec2.SetX(3);
  vec2.SetY(4);

  /* Прибавляем vec1 к вектору vec2. */
  vec1.AddMeToAnotherVector(vec2);

  /* Выведет 4 и 6. */
  std::cout << "vec2.x = " << vec2.GetX()
            << " vec2.y = " << vec2.GetY() << std::endl;
  return 0;
}

