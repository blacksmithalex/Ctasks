#include <iostream>

class Matrix {
 private:
  double* data;
  std::size_t numRows;
  std::size_t numCols;

 public:
  Matrix(std::size_t numRows, std::size_t numCols) :
    data(new double[numRows * numCols]),
    numRows(numRows),
    numCols(numCols)
  {
    /* Зануляем все элементы. */
    for (std::size_t row = 0; row < numRows; row++) {
      for (std::size_t col = 0; col < numCols; col++)
        data[row * numCols + col] = 0;
    }
  }

  ~Matrix() {
    if (data)
      delete[] data;
  }

  std::size_t NumRows() const { return numRows; }
  std::size_t NumCols() const { return numCols; }

  /* Операция индексации кроме самого объекта принимает ещё один аргумент: индекс.
     Причем индекс может быть любого типа, он не обязан быть целочисленным. Для
     матрицы логично, чтобы индекс был целочисленным. Первая операция предназначена
     для чтения. */
  double operator[](std::size_t index) const {
    return data[index];
  }

  /* Эта операция предназначена для записи. Она возвращает ссылку. */
  double& operator[](std::size_t index) {
    return data[index];
  }

  /* Операция функционального вызова может принимать любое количество аргументов любого
     типа. Для матрицы логично сделать два целочисленных аргумента: номер строки и
     номер столбца. Операция для чтения. */
  double operator()(std::size_t row, std::size_t col) const {
    return data[row * numCols + col];
  }

  /* Операция для записи. */
  double& operator()(std::size_t row, std::size_t col) {
    return data[row * numCols + col];
  }
};

int main() {
  Matrix m(5, 5);

  /* Запись элементов при помощи операции индексирования. */
  m[3] = 10;
  m[14] = 5;

  for (std::size_t row = 0; row < m.NumRows(); row++) {
    for (std::size_t col = 0; col < m.NumCols(); col++) {
      /* Чтение при помощи операции индексирования. */
      std::cout << m[row * m.NumCols() + col] << " ";
    }

    std::cout << std::endl;
  }

  /* Запись элементов при помощи операции функционального вызова. */
  m(1, 2) = 11;
  m(4, 3) = 4;

  for (std::size_t row = 0; row < m.NumRows(); row++) {
    for (std::size_t col = 0; col < m.NumCols(); col++) {
      /* Чтение при помощи операции функционального вызова. */
      std::cout << m(row, col) << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}

