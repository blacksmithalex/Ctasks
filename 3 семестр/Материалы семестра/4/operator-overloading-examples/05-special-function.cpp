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
};

/* Перегружаем операцию сложения для двух комплексных чисел. Поскольку функция написана
   отдельно от класса, в неё не передаются аргументы неявным образом. Кроме того,
   функция не может обращаться к приватным полям класса напрямую. В остальном всё то же
   самое. По смыслу аргументы не должны меняться и функция создаёт новый объект. */
Complex operator+(const Complex& left, const Complex& right) {
  return Complex(left.Re() + right.Re(), left.Im() + right.Im());
}

/* По смыслу первый аргумент может измениться, второй меняться не должен, операция
   не создаёт новых объектов. */
Complex& operator+=(Complex& left, const Complex& right) {
  left.Re() += right.Re();
  left.Im() += right.Im();

  return left;
}

Complex operator-(const Complex& left, const Complex& right) {
  return Complex(left.Re() - right.Re(), left.Im() - right.Im());
}

/* Унарная операция "минус", мы должны явно указать аргумент. */
Complex operator-(const Complex& argument) {
  return Complex(-argument.Re(), -argument.Im());
}

Complex& operator-=(Complex& left, const Complex& right) {
  left.Re() -= right.Re();
  left.Im() -= right.Im();
  return left;
}

int main() {
  Complex c1(1, 2);
  Complex c2(3, 4);
  Complex c3;

  // Здесь вызывается функция operator+(), и в неё передаются аргументы c1 и c2.
  c3 = c1 + c2;

  // Это эквивалентно следующей строчке:
  c3 = operator+(c1, c2);

  /* Пример использования операции +=. */
  c3 += c2;

  /* Пример использования унарного минуса. */
  c3 = -c2;

  std::cout << "(" << c3.Re() << ", " << c3.Im() << ")" << std::endl;
  return 0;
}
