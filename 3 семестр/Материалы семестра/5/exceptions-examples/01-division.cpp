#include <iostream>
#include <cmath>

double Divide(double left, double right) {
  if (std::fabs(right) < 1e-14) {
    /* Попытка деления на нуль. Генерируем исключение. */
    throw "Division by zero.";
  }

  /* Выполняем операцию деления. */
  return left / right;
}

int main() {
  double a, b, c = 0;

  std::cin >> a >> b;

  try {
    /* Исключение не обязательно нужно генерировать явно в блоке try. Оно может быть
       сгенерировано какой-либо функцией, вызывающейся в блоке try, и обработано
       в соответствующем ему блоке catch. */
    c = Divide(a, b);
  } catch(const char* e) {
    /* Словили исключение. Выводим информацию о нём. */
    std::cout << "Got an exception. Reason: " << e << std::endl;
  }

  std::cout << "Result: " << c << std::endl;
  return 0;
}

