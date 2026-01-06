#include <iostream>
#include <string>

class Complex {
 private:
  double re;
  double im;
 public:
  Complex() :
    re(0),
    im(0)
  { }

  /* Конструктор принимает только один параметр. В таком случае он задаёт правило
     конвертации типа аргумента (double) в тип данных класса (Complex). */
  Complex(double re) :
    re(re),
    im(0)
  { }

  /* Неявное приведение типа при помощи конструктора можно запретить при помощи
     ключевого слова explicit. В данном случае запрещается неявная конвертация из типа
     std::string в тип Complex. Функция std::stod() из заголовочного файла <string>
     конвертирует строку std::string в тип double. */
  explicit Complex(const std::string& re) :
    re(std::stod(re)),
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
};

void PrintComplex(const Complex& number) {
  std::cout << "(" << number.Re() << ", " << number.Im() << ")" << std::endl;
}

int main() {
  Complex c;

  /* Здесь тип double неявно конвертируется в тип данных Complex при помощи написанного
     нами конструктора. */
  c = 5.3;

  std::cout << "(" << c.Re() << ", " << c.Im() << ")" << std::endl;

  /* При вызове функции аргумент конвертируется в тип Complex. */
  PrintComplex(3.14);

  /* Неявная операция приведения типа std::string в тип Complex запрещена при помощи
     ключевого слова explicit. */
  // c = std::string("125.3"); // Ошибка компиляции из-за explicit.

  /* А вот так можно. Явно вызываем конструктор. */
  c = Complex(std::string("125.3"));

  // И вот так тоже можно. Тип std::string может быть неявно создан из типа const char*.
  c = Complex("125.3");

  std::cout << "(" << c.Re() << ", " << c.Im() << ")" << std::endl;
  return 0;
}

