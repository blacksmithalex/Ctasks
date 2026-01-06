#include <iostream>

class Complex {
 private:
  double re;
  double im;
 public:
  /* Этот конструктор служит и в качестве конструктора по-умолчанию и в качестве
     операции приведения типа, и в качестве специального конструктора. */
  Complex(double re = 0, double im = 0) :
    re(re),
    im(im)
  { }

  /* Операция конвертации в тип данных double. Тип может быть любой, он указывается
     после слова operator. Тип возвращаемого значения указывать не нужно, он совпадает
     с указанным после слова operator. */
  operator double() const {
    /* Просто возвращаем действительную часть числа. */
    return re;
  }
};

int main() {
  Complex c(1, 3);

  /* Неявная конвертация типа  Complex в тип double. */
  double re = c;

  std::cout << "Re: " << re << std::endl;
  return 0;
}

