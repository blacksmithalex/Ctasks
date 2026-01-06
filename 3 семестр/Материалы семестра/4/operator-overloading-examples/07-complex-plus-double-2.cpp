#include <iostream>

class Complex {
 private:
  double re;
  double im;
 public:
  Complex(double re = 0, double im = 0) :
    re(re),
    im(im)
  { }

  double Re() const { return re; }
  double& Re() { return re; }
  double Im() const { return im; }
  double& Im() { return im; }
};

/* Эта функция перегружает операцию вычитания для двух аргументов типа Complex. */
Complex operator- (const Complex& left, const Complex& right) {
  return Complex(left.Re() - right.Re(), left.Im() - right.Im());
}

int main() {
  Complex c1(1, 2);
  Complex c2;

  /* Здесь целое число неявно преобразуется в double, а затем в тип Complex при помощи
     написанного нами конструктора. */
  c2 = c1 - 5;

  /* Здесь целое число неявно преобразуется в double, а затем в тип Complex при помощи
     написанного нами конструктора. */
  c2 = 3 - c1;

  std::cout << "(" << c2.Re() << ", " << c2.Im() << ")" << std::endl;
  return 0;
}

