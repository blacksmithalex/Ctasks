#include <iostream>
#include <cstring> // Это для std::strncpy()

class String {
 private:
  char* data;
  std::size_t size;
 public:
  String() :
    data(nullptr),
    size(0)
  { }

  String(const char* str) :
    data(nullptr),
    size(std::strlen(str))
  {
    data = new char[size + 1];

    /* Копируем поэлементно. */
    std::strncpy(data, str, size + 1);
  }

  ~String() {
    if (data)
      delete[] data;
  }

  /* Операция для копирования объекта из другого объекта того же типа принимает
     константную ссылку на объект того же типа и возвращает обычную ссылку на сам
     объект (для того, чтобы можно было написать A = B = C). */
  String& operator=(const String& other) {
    /* Сначала нужно освободить память, если таковая была выделена. */
    if (data)
      delete[] data;

    data = nullptr;
    size = other.size;

    if (other.data) {
      /* Выделяем память, если есть, что копировать. */
      data = new char[size + 1];

      /* Копируем поэлементно. */
      std::strncpy(data, other.data, size + 1);
    }

    /* Возвращаем ссылку на себя же. */
    return *this;
  }

  const char* Data() const { return data; }
};

int main() {
  String str("Hello world!");
  String strCopy;

  /* Вот здесь вызывается операция копирующего присваивания. */
  strCopy = str;

  std::cout << strCopy.Data() << std::endl;
  return 0;
}

