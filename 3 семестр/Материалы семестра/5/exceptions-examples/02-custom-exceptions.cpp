#include <iostream>
#include <cstdio>
#include <stdexcept>

/* Специальный тип исключения для обработки ошибок ввода/вывода. */
class IOError {
 private:
  std::string reason;
 public:
  IOError(const std::string& reason) :
    reason(reason)
  { }

  const std::string& Reason() const { return reason; }
};

/* Специальный тип исключения для обработки ошибок, связанных с некорректными
   значениями. */
class ValueError {
 private:
  std::string reason;
 public:
  ValueError(const std::string& reason) :
    reason(reason)
  { }

  const std::string& Reason() const { return reason; }
};

/* А это класс для чтения данных из файла. Класс в конструкторе открывает файл,
   а в деструкторе его самостоятельно закрывает. */
class FileReader {
 private:
  std::FILE* file;
 public:
  FileReader(const char* filename) :
    file(std::fopen(filename, "rt"))
  {
    if (!file) {
      /* Не смогли открыть файл. Выбрасываем исключение. */
      throw IOError("Can't open file");
    }
  }

  ~FileReader() {
    if (file)
      std::fclose(file);
  }

  double ReadDouble() const {
    double value;

    if (std::fscanf(file, "%lf", &value) != 1) {
      /* Не получилось считать значение. Генерируем исключение. */
      throw IOError("Can't read the next value.");
    }

    return value;
  }

  double ReadInt() const {
    int value;

    if (std::fscanf(file, "%d", &value) != 1) {
      /* Не получилось считать значение. Генерируем исключение. */
      throw IOError("Can't read the next value.");
    }

    return value;
  }
};

void ReadMatrix(const FileReader& reader, double* matrix, int numRows, int numCols) {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      /* Метод ReadDouble() может сгенерировать исключение IOError. */
      matrix[row * numCols + col] = reader.ReadDouble();
    }
  }
}

int main() {
  double* matrix = nullptr;

  try {
    /* Конструктор может сгенерировать исключение IOError. */
    FileReader reader("input.txt");

    /* Метод ReadInt() может сгенерировать исключение IOError. */
    int numRows = reader.ReadInt();
    int numCols = reader.ReadInt();

    if (numRows <= 0 || numCols <= 0) {
      throw ValueError("Incorrect matrix dimensions.");
    }

    /* Оператор new может сгенерировать исключение std::bad_alloc. */
    matrix = new double[numRows * numCols];

    /* Функция ReadMatrix() может сгенерировать исключение IOError. */
    ReadMatrix(reader, matrix, numRows, numCols);
  } catch (const IOError& e) {
    std::cout << "Input/output error. Reason: " << e.Reason() << std::endl;

  } catch (const ValueError& e) {
    std::cout << "Value error. Reason: " << e.Reason() << std::endl;
  } catch (const std::bad_alloc& e) {
    /* Исключение типа std::bad_alloc из заголовочного файла <stdexcept> генерирует
       оператор new в случае ошибки выделения памяти. */
    std::cout << "Can't allocate memory! Reason: " << e.what() << std::endl;
  }

  if (matrix)
    delete[] matrix;
  return 0;
}

