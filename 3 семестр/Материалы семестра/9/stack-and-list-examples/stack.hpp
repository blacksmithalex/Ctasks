#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept> // Файл, необходимый для работы со стандартными исключениями

// Класс, описывающий ячейку стека
struct StackNode {
  int value;       // Число, которое лежит в текущей ячейке стека
  StackNode* prev; // Указатель на предыдущую ячейку
  
  // Конструктор ячейки. По умолчанию считаем, что это первая ячейка
  StackNode(int value, StackNode* prev = NULL) :
      value(value),   // Записываем значение в ячейку
      prev(prev)
  { }
};

class Stack {
 public:
  Stack() :
      topNode(NULL), // Это верхний элемент стека. По умолчанию стек пустой.
      size(0)        // Иногда бывает полезно запоминать размер стека. Это необязательно.
  { }
  ~Stack() {
    while (topNode != NULL) {  // Итерируемся по стеку и освобождаем память
      StackNode* tmp = topNode;

      topNode = topNode->prev; // Переходим на предыдущую ячейку
      delete tmp;              // Удаляем ячейку, с которой только что перешли.
    }
  }
  
  // Кладём элемент в стек
  void Push(int value) {
    // Создаём новую ячейку стека, хранящую значение value, говорим, что
    // весь накопленный стек хранится перед ней, и записываем указатель на неё в topNode.
    // Таким образом, topNode указывает на верхушку стека.
    topNode = new StackNode(value, topNode);
    size++;
  }
  
  // Удаляем элемент из стека
  void Pop() {
    if (topNode == NULL) // Если стек пустой, кидаем исключение.
      throw std::out_of_range("Stack is empty!");
    
    StackNode* tmp = topNode;

    topNode = topNode->prev; // Переходим на предыдущую ячейку
    delete tmp;              // Удаляем ячеку, с которой только что перешли.
    size--;
  }
  
  // Просматриваем последний добавленный элемент
  int Top() const {
    if (topNode == NULL) // Если стек пустой, кидаем исключение.
      throw std::out_of_range("Stack is empty!");

    return topNode->value;
  }
  
  // Возвращаем размер стека
  std::size_t Size() const { return size; }
  
  // Является ли стек пустым?
  bool Empty() const { return topNode == NULL; }

 private:
  StackNode* topNode;  // Указатель на верхнюю ячейку стека
  std::size_t size;    // Размер стека
};

#endif // STACK_HPP
