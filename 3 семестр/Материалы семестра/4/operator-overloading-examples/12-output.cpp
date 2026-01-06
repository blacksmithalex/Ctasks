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

/* Определим операцию << для использования в потоках вывода. Будем считать, что любой
   поток, предназначенный для вывода, например, std::cout, имеет тип std::ostream
   (почти), определённый в заголовочном файле <ostream>. Соответственно, нам необходимо
   определить операцию << для типов std::ostream и Complex. */
std::ostream& operator<<(std::ostream& out, const Complex& number) {
  out << "(" << number.Re() << ", " << number.Im() << ")";

  return out;
}

int main() {
  Complex c(1, 3);

  std::cout << "Number: " << c << "\n";

  /* Эквивалентно: 
     Операция выполняется слева направо. */
  ((std::cout << "Number: ") << c) << "\n";
  /* Или эквивалентно: 
     Поскольку операция возвращает сам поток (то есть ссылку на него), операцию можно
     применять цепочкой. */
  operator<<(operator<<(operator<<(std::cout, "Number: "), c), "\n");

  return 0;
}

