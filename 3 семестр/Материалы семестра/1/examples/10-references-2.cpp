#include <iostream>
#include <string>

void PrintLine(const std::string& str) {
  std::cout << str << std::endl;
}

/* Если размер типа данных передаваемого аргумента превышает 16 байт, то его имеет смысл
   передавать по ссылке. Для типа int это конечно же не нужно, однако как то так это
   может выглядеть. */
int Sum(const int& left, const int& right) {
  return left + right;
}

int main() {
  return 0;
}
