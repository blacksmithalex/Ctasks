#include <cstdlib>

using namespace std;

int main() {
  const int a = 5;

  // a = 10; // Ошибка на этапе компиляции.

  /* ptr является указателем на элементы типа const int. Это означает, что элементы
     массива нельзя менять, однако само значение указателя может быть изменено. */
  const int* ptr;

  // Сам указатель менять можно
  ptr = (const int*) malloc(sizeof(int));

  // ptr[0] = 10; // Ошибка на этапе компиляции.

  /* Ошибка компиляции, функция free() принимает указатель на void (без const), значит,
     теоретически она может менять содержимое массива, а мы передаём указатель на
     константу. */
//  free(ptr);

  int* const constPtr = (int* const) malloc(sizeof(int));

  constPtr[0] = 10; // Корректно

  // constPtr = NULL; // Ошибка на этапе компиляции

  /* Всё в порядке */
  free(constPtr);

  const int* const constPtrToConst = (const int* const) malloc(sizeof(int));

  // constPtrToConst[0] = 10; // Ошибка на этапе компиляции
  // constPtrToConst = NULL; // Ошибка на этапе компиляции

  /* Ошибка компиляции, функция free() принимает указатель на void (без const), значит,
     теоретически она может менять содержимое массива, а мы передаём указатель на
     константу. */
//  free(constPtrToConst);

  return 0;
}
