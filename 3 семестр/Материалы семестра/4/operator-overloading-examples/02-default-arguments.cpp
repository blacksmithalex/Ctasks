#include <iostream>

class Complex {
 private:
  double re;
  double im;
 public:
  /* Этот конструктор служит и в качестве конструктора по-умолчанию и в качестве
     операции приведения типа, и в качестве специального конструктора. При вызове такого
     конструктора последние необязательные аргументы можно не задавать, однако, их
     нельзя пропускать. То есть нельзя задать только аргумент im. */
  Complex(double re = 0, double im = 0) :
    re(re),
    im(im)
  { }

  double Re() const { return re; }
  double& Re() { return re; }
  double Im() const { return im; }
  double& Im() { return im; }
};

void PrintComplex(const Complex& number) {
  std::cout << "(" << number.Re() << ", " << number.Im() << ")" << std::endl;
}

int main() {
  /* Все способы создания комплексного числа работают. */
  Complex c;
  Complex c2(1, 5);
  Complex c3(4);

  /* Здесь тип double неявно конвертируется в тип данных Complex при помощи написанного
     нами конструктора. */
  c = 5.3;

  /* При вызове функции аргумент конвертируется в тип Complex. */
  PrintComplex(3.14);

  std::cout << "(" << c.Re() << ", " << c.Im() << ")" << std::endl;
  std::cout << "(" << c2.Re() << ", " << c2.Im() << ")" << std::endl;
  std::cout << "(" << c3.Re() << ", " << c3.Im() << ")" << std::endl;
  return 0;
}

