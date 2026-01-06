#include <iostream>
#include <string>

class Logger {
 private:
  std::string name;
 public:
  /* Конструктор принимает имя объекта и выводит информацию о том, что он создан. */
  Logger(const std::string& logerName) {
    name = logerName;
    std::cout << "Object '" << name << "' created!" << std::endl;
  }
  
  /* Деструктор выводит информацию о том, что объект удалён. */
  ~Logger() {
    std::cout << "Object '" << name << "' destroyed!" << std::endl;
  }
};

class Base {
 private:
  Logger field1;
  Logger field2;
  std::string name;

 public:
  /* Имя аргумента метода может совпадать с именем поля класса. В таком случае
     будет виден только аргумент функции (обратиться к соответствующему полю класа
     тоже можно, но об этом на следующих занятиях). В данном примере компилятор
     понимает, что поле name класса инициализируется аргументом name конструктора. 
     Операция сложения для типа std::string создаёт новую строку, являющуюся
     объединением строк-аргументов операции. */
  Base(const std::string& name) :
    field1(name + ".field1"),
    field2(name + ".field2"),
    name(name) // Здесь поле name инициализируется аргументом name
  {
    /* А вот здесь name ассоциируется с аргументом конструктора, а не с полем класса.
      В конструкторах field1 и field2 тоже используется аргумент name, а не поле
      класса name. */
      
    std::cout << "Base class '" << name << "' created!" << std::endl;
  }

  ~Base() {
    std::cout << "Base class '" << name << "' destroyed!" << std::endl;
  }
};

int main() {
  Base base1("base1");
  Base base2("base2");

  return 0;
}

