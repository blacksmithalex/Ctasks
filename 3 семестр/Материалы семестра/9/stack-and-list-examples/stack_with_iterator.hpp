#ifndef STACK_WITH_ITERATOR_HPP
#define STACK_WITH_ITERATOR_HPP

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

class StackWithIterator {
  // Вначале идут все те же поля и методы, что и в классе Stack.
 public:
  StackWithIterator() :
      topNode(NULL), // Это верхний элемент стека. По умолчанию стек пустой.
      size(0)        // Иногда бывает полезно запоминать размер стека. Это необязательно.
  { }
  ~StackWithIterator() {
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

  // А теперь начинаются отличия
 public:
  // Сначала определим так называемый константный итератор, который
  // не может менять элементы, на которые он указывет.
  class ConstIterator {
   public:
    ConstIterator(const StackNode* currentNode = NULL) :
        currentNode(currentNode)
    { }

    int operator*() const { // Разыменовываем итератор
      return currentNode->value;
    }
    ConstIterator& operator++() { // Переходим к следующей ячейке
      currentNode = currentNode->prev;
      return *this;
    }
    
    // Для сравнения итераторов нам необходимо определить операции сравнения
    bool operator!=(const ConstIterator& other) const {
      return currentNode != other.currentNode;
    }

    bool operator==(const ConstIterator& other) const {
      return currentNode == other.currentNode;
    }
   private:
     // Это указатель на константу, сам указатель менять можно,
     // а то, на что он указывает -- нет.
    const StackNode* currentNode;
  };

  // Теперь определим итаратор, который может менять элементы,
  // на которые он указывает.
  class Iterator {
   public:
    Iterator(StackNode* currentNode = NULL) :
        currentNode(currentNode)
    { }
    
    // Разыменовываем итератор. Метод возвращает ссылку на элемент.
    int& operator*() const {
      return currentNode->value;
    }
    Iterator& operator++() { // Переходим к следующей ячейке
      currentNode = currentNode->prev;
      return *this;
    }
    
    // Для сравнения итераторов нам необходимо определить операцию сравнения
    bool operator!=(const Iterator& other) const {
      return currentNode != other.currentNode;
    }

    bool operator==(const Iterator& other) const {
      return currentNode == other.currentNode;
    }
   private:
    StackNode* currentNode; // Указатель на текущую ячейку
  };

  // Константный итератор на начало промежутка
  ConstIterator Begin() const { return ConstIterator(topNode); }
  // Константный итератор на конец промежутка (указывает на элемент "после последнего")
  ConstIterator End() const { return ConstIterator(); }
  // Итератор на начало промежутка
  Iterator Begin() { return Iterator(topNode); }
  // Итератор на конец промежутка (указывает на элемент "после последнего")
  Iterator End() { return Iterator(); }
};

#endif // STACK_WITH_ITERATOR_HPP
