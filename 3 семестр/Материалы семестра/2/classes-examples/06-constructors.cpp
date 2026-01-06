#include <iostream>

class Vector2d {
 private:
  double x;
  double y;
 public:
  // Стандартный конструктор. Вызывается при объявлении переменной -- объекта класса.
  Vector2d() {
    x = 0;
    y = 0;
  }

  /* Конструктор копирования. */
  Vector2d(const Vector2d& other) {
    x = other.x;
    y = other.y;
  }

  /* Специальный конструктор. */
  Vector2d(double xArg, double yArg) {
    x = xArg;
    y = yArg;
  }

  double X() const { return x; }
  double Y() const { return y; }
};

int main() {
  /* Здесь вызывается стандартный конструктор (при объявлении переменной). */
  Vector2d vec;
  /* Создаём vecCopy из объекта vec при помощи конструктора копирования. */
  Vector2d vecCopy(vec);
  /* Наконец, специальный конструктор позволяет сразу при объявлении инициализировать
     поля класса (только по той простой причине, что мы его таким написали). */
  Vector2d anotherVec(10, 5);

  /* Выведет 10 и 5. */
  std::cout << "anotherVec.x = " << anotherVec.X()
            << "anotherVec.y = " << anotherVec.Y() << std::endl;

  /* Можно вызвать конструктор класса явно (совпадает с именем класса), 
     он создаст новый объект. Выведет 3 и 4.*/
  vec = Vector2d(3, 4);

  std::cout << "vec.x = " << vec.X()
            << "vec.y = " << vec.Y() << std::endl;
  return 0;
}

