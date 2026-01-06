class VectorNd {
 private:
  double* data;
  int size;
 public:
  /* Конструктор выделяет память. */
  VectorNd(int count) {
    data = new double[count];
    size = count;
  }

  /* Деструктор освобождает память. */
  ~VectorNd() {
    delete[] data;
  }
};

int main() {
  return 0;
}

