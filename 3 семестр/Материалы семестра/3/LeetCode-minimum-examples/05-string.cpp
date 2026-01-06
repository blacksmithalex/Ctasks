#include <iostream>
#include <string>
#include <cstdio> // Это для функции std::printf

int main() {
  std::string str = "Hello world!"; // Инициализация объекта из типа const char*
  // Методы length() и size() класса std::string позволяют узнать длину строки
  std::cout << "The length of string '" << str << "' is equal to " 
            << str.length() << std::endl;
  /* Тип std::size_t хранит целые неотрицательные числа. Его размер позволяет хранить 
     указатель. Все контейнеры C++ возвращают размер в std::size_t. */
  std::size_t size = str.size();
  std::cout << "The size is equal to " << size << std::endl;
  /* Оператор [], переопределённый для класса std::string позволяет читать и 
     модифицировать отдельные символы. Нумерация ведётся с нуля. */
  str[6] = 'W';
  std::cout << "Modified string: '" << str << "'" << std::endl;

  // Строки можно считывать с помощью класса std::cin.
  std::cout << "Enter your name-> ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name << "!" << std::endl;

  /* Объекты класса std::string можно сравнивать не только между собой, но и с типами
     const char* (строками в кавычках). Сравнение производится в лексикографическом
     порядке. */
  if (name == "Mikhail")
    std::cout << "Nice to meet you!" << std::endl;
  if (name < "Mikhail")
    std::cout << "Your name is inappropriate!" << std::endl;

  /* Объекты типа std::string можно складывать в том числе и со строками в кавычках
     (const char*). Результатом является объединение строк. */
  std::string result = name + " knows how to use strings in C++";
  std::cout << result << std::endl;

  /* Наконец, объекты типа std::string могут возвращать указатели на const char
    (то есть const char*), иными словами, строки в стиле языка C. Примечание:
    слово 'const' говорит о том, что элементы получившейся строки нельзя менять. */
  const char* cStyleString = result.c_str();
  std::printf("C-style: %s\n", cStyleString);

  return 0;
}

