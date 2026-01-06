class Vector2d {
 private:
  double x;
  double y;
 public:
  /* Метод не меняет полей класса, значит его нужно сделать константным. */
  double GetX() const {
    return x;
  }

  /* Метод меняет поле класса, поэтому он не является константным. */
  void SetX(double xArg) {
    x = xArg;
  }

  double GetY() const {
    return y;
  }

  void SetY(double yArg) {
    y = yArg;
  }
};

int main() {
  return 0;
}
