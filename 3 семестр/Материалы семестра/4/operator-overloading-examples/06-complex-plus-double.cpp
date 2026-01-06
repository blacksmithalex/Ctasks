#include <iostream>

class Complex {
 private:
  double re;
  double im;
 public:
  Complex() :
    re(0),
    im(0)
  { }

  Complex(double re, double im) :
    re(re),
    im(im)
  { }

  double Re() const { return re; }
  double& Re() { return re; }
  double Im() const { return im; }
  double& Im() { return im; }

  /* Этот метод перегружает операцию с левым аргументом типа Complex и правым
     аргументом типа double. */
  Complex operator-(double number) const {
    return Complex(re - number, im);
  }
};

/* А вот эта функция перегружает операцию с левым аргументом типа double и правым
   аргументом типа Complex. По смыслу операция не меняет своих аргументов и
   возвращает комплексное число. */
Complex operator-(double number, const Complex& right) {
  return Complex(number - right.Re(), - right.Im());
}

int main() {
  Complex c1(1, 2);
  Complex c2;

  /* Здесь работает метод. */
  c2 = c1 - 5;

  /* А вот здесь метод сработать не может, здесь работает функция. */
  c2 = 3 - c1;

  std::cout << "(" << c2.Re() << ", " << c2.Im() << ")" << std::endl;
  return 0;
}

