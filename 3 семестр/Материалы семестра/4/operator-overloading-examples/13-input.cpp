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

/* Определим операцию >> для использования в потоках ввода. Будем считать, что любой
   поток, предназначенный для ввода, например, std::cin, имеет тип std::istream (почти),
   определённый в заголовочном файле <istream>. Соответственно, нам необходимо
   определить операцию >> для типов std::istream и Complex. */
std::istream& operator>>(std::istream& in, Complex& number) {
  in >> number.Re() >> number.Im();

  return in;
}

int main() {
  Complex c;

  /* Использование операции для чтения комплексного числа. */
  std::cin >> c;

  std::cout << c.Re() << " " << c.Im() << std::endl;
  return 0;
}

