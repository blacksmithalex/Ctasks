class String {
 private:
  char* data;
  int size;
 public:
  /* В C++11 следует использовать nullptr вместо NULL. */
  String() :
    data(nullptr),
    size(0)
  { }

  String(const String& other) :
    data(nullptr),
    size(other.size)
  {
    if (size > 0) {
      data = new char[size + 1];
    }

    /* Копируем строки посимвольно. */
    for (int i = 0; i < size; i++)
      data[i] = other.data[i];

    /* Прописываем символ конца строки. */
    data[size] = 0;
  }

  ~String() {
    if (data)
      delete[] data;
  }
};

int main() {
  return 0;
}
