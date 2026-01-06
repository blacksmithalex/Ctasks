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

  /* Префиксная операция инкремента. Она меняет объект и возвращает его же.
     Новых объектов не создаётся. */
  Complex& operator++() {
    re += 1;
    return *this;
  }

  /* Постфиксная операция. При объявлении необходимо указать формальный неиспользуемый 
     аргумент любого типа, например, int для того, чтобы отличить операцию от префиксной
     (весьма неочевидный костыль C++). Перед изменением объекта его приходится сначала
     скопировать, чтобы вернуть неизменённую копию. Таким образом, операция создаёт
     новый объект. */
  Complex operator++(int) {
    Complex other(*this);
    re += 1;
    return other;
  }
};

void PrintComplex(const Complex& c) {
  std::cout << "(" << c.Re() << ", " << c.Im() << ")" << std::endl;
}

int main() {
  Complex c(3, 1);

  PrintComplex(c);

  /* Префиксная операция. */
  PrintComplex(++c);

  PrintComplex(c);

  /* Постфиксная операция. */
  PrintComplex(c++);

  PrintComplex(c);
  return 0;
}

