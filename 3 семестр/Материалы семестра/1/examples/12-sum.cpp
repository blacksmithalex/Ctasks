#include <iostream>

bool ReadArray(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    if (std::cin >> arr[i])
      return false;
  }

  return true;
}

/* Передача массива в функцию по указателю позволяет менять его содержимое внутри
   функции. В случае если содержимое массива меняться не должно, сама возможность может
   потенциально привести к ошибке. Поэтому считается хорошим тоном саму эту возможность
   запретить. Это делается при помощи ключевого слова const. В данном случае arr
   является указателем на элементы типа const int, то есть элементы массива не могут
   меняться. */
int Sum(const int* arr, int n) {
  int result = 0;

  for (int i = 0; i < n; i++)
    result += arr[i];

  return result;
}

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
    std::cout << "Result: 0" << std::endl;
    return 0;
  }

  /* Оператор new[] генерирует исключение (см. следующие занятия) в случае ошибки
     выделения памяти. Проверку возвращаемого значения делать не нужно. */
  int* arr = new int[n];

  /* Тип данных int* можно неявно преобразовать к const int*. Всё в порядке. */
  if (!ReadArray(arr, n)) {
    std::cerr << "Can't read array!" << std::endl;
    return 4;
  }

  std::cout << "Result: " << Sum(arr, n) << std::endl;

  delete[] arr;

  return 0;
}

