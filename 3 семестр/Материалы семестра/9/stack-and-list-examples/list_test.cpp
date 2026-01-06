#include <iostream>
// Реализация нашего класса List
#include "list.hpp"
    
void PrintList(const List& list) {
  std::cout << "List:" << std::endl;
  for (List::ConstIterator it = list.Begin();
       it != list.End();
       ++it) {
    std::cout << *it << std::endl;
  }
}

void PrintListReversed(const List& list) {
    std::cout << "Reversed List:" << std::endl;
    for (List::ConstReverseIterator it = list.RBegin();
         it != list.REnd();
         ++it) {
    std::cout << *it << std::endl;
  }
}

List::Iterator LowerBound(List::Iterator listBegin, List::Iterator listEnd, int elem) {
  for (List::Iterator it = listBegin; it != listEnd; ++it) {
    if (*it >= elem)
      return it;
  }
  return listEnd;
}

void ReadListAndSort(List& list) {
  int elem;
  
  while (std::cin >> elem) {
    List::Iterator pos = LowerBound(list.Begin(), list.End(), elem);
    list.Insert(pos, elem);
  }
}

int main() {
  List list;
  
  ReadListAndSort(list);
  
  PrintList(list);
  
  PrintListReversed(list);
  return 0;
}

