#include <iostream>
#include <cstdio>

/* Функция читает целое число из заранее открытого файла. В случае ошибки генерируется
   исключение. */
int DoRead(std::FILE* file) {
  int value;

  if (std::fscanf(file, "%d", &value) != 1) {
    /* Не получилось считать число. Генерируем исключение. */
    throw std::string("Can't read value.");
  }

  return value;
}

int ReadIntFromFile(const char* filename) {
  std::FILE* file = std::fopen(filename, "rt");
  int value = 0;

  if (!file) {
    /* Не открылся файл. Выбрасываем исключение. */
    throw std::string("Can't open file!");
  }

  try {
    /* Функция DoRead() может сгенерировать исключение. Если его не обработать
       внутри текущей функции, то файл останется открыт. */
    value = DoRead(file);
  } catch (const std::string& e) {
    /* Не получилось считать данные из файла. Нужно закрыть файл,
       а затем пробросить исключение вверх по стеку. */
    std::fclose(file);

    /* Пробрасываем исключение вверх по стеку. */
    throw;
  }

  /* Если функция DoRead() выбрасывает исключение, то этот код не выполняется.
     Таким образом, файл мог бы остаться открытым, если бы не был написан правильный
     обработчик. */
  std::fclose(file);

  return value;
}

int main() {
  try {
    int value = ReadIntFromFile("input.txt");

    std::cout << "Value: " << value << std::endl;
  } catch (const std::string& e) {
    std::cout << "Got an exception. Reason: " << e << std::endl;
  }
  return 0;
}

