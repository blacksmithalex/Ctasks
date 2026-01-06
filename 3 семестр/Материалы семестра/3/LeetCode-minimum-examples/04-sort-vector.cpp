#include <iostream>
#include <vector>
#include <algorithm> // Это для функции std::sort

int main() {
  /* Функция std::sort библиотеки <algorithm> позволяет отсортировать промежуток
     вектора, заданный итераторами.
  */

  /* Элементы вектора можно задавать списком инициализации, начиная с C++11. */
  std::vector<int> v = {1, 4, 8, 3, 8, 2, 5, 7, 9, 5, 3, 2, 5, 8, 4, 4, 7};

  /* Сортируем первые 10 элементов вектора. Прибавление числа к итератору вектора
     работает точно так же, как и для указателей. */
  std::sort(v.begin(), v.begin() + 10);

  for (std::size_t i = 0; i < v.size(); i++)
    std::cout << v[i] << std::endl;

  std::sort(v.begin(), v.end());        // Сортируем весь вектор.

  for (std::size_t i = 0; i < v.size(); i++)
    std::cout << v[i] << std::endl;

  return 0;
}

