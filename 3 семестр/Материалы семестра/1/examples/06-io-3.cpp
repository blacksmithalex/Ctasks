#include <iostream>

int main() {
  int n;

  if (!(std::cin >> n)) {
    std::cerr << "Can't read n!" << std::endl;
    return 1;
  }

  if (n < 0) {
    std::cerr << "n < 0!" << std::endl;
    return 2;
  }

  if (n == 0) {
    // Выводим результат в стандартный поток вывода.
    std::cout << "Result: 0" << std::endl;
    return 0;
  }

  /* В языке C++ разрешено перемешивать объявления переменных и код. В некоторых
     случаях переменные следует объявлять по мере необходимости, а не в начале блока. */
  double sum = 0;

  /* Внутри цикла for можно объявлять переменные-счётчики. Рекомендуется именно так и
     делать, чтобы не плодить лишние сущности. */
  for (int i = 0; i < n; i++) {
    double number;

    if (!(std::cin >> number)) {
      std::cerr << "Can't read the next number!" << std::endl;
      return 1;
    }

    sum += number;
  }

  sum /= n;

  std::cout << "Result: " << sum << std::endl;
  return 0;
}

