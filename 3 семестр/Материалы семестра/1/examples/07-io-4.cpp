#include <iostream>

int main() {
  int n = 0;
  double sum = 0;
  double number;
  /* Эта конструкция будет считывать действительные числа из стандартного потока ввода
     до тех пор, пока они считываются. */
  while (std::cin >> number) {
    sum += number;
    n++;
  }

  if (n > 0)
    sum /= n;

  std::cout << "Result: " << sum << std::endl;
  return 0;
}

