#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = { 1, 2, 4, 7, 3, 5, 6, 7, 3, 2 };

  /* Итерация по значению. */
  for (auto item : vec)
    std::cout << item << std::endl;

  /* Итерация по ссылке позволяет менять элементы вектора. */
  for (auto& item : vec)
    std::cin >> item;

  return 0;
}

