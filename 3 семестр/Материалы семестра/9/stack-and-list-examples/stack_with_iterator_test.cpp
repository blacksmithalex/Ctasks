#include <iostream>
// Файл с определением нашего класса StackWithIterator
#include "stack_with_iterator.hpp"

void ReadStack(StackWithIterator& stack) {
  int elem;
  while (std::cin >> elem) {
    stack.Push(elem);
  }
}

void PrintStack(const StackWithIterator& stack) {
  // Итерируемся по циклу с помощью константного итератора ввиду того, что
  // в функцию передана ссылка на const StackWithIterator
  // Инициализируем итератором на начало
  for (StackWithIterator::ConstIterator it = stack.Begin();
       it != stack.End();                       // Проверяем, дошли ли до конца
       ++it) {                                  // Переходим к следующему итератору
    // *it возвращает элемент стека типа int
    std::cout << *it << std::endl;
  }
}

void Process(StackWithIterator& stack) {
  // Модифицируем элементы, поэтому итератор неконстантный
  StackWithIterator::Iterator it = stack.Begin();
  int prevValue = *it;
  ++it; // Переходим к следующему элементу

  for (; it != stack.End(); ++it) {
    int tmp = *it;
    *it += prevValue;
    prevValue = tmp;
  }
}

int main() {
  StackWithIterator stack;

  ReadStack(stack);

  Process(stack);

  PrintStack(stack);

  return 0;
}
