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

  /* По смыслу операция не должна менять своих аргументов и должна возвращать true
     или false. */
  bool operator<(const Complex& other) const {
    if (re < other.re)
      return true;
    if (re > other.re)
      return false;

    return im < other.im;
  }
};

int main() {
  Complex c1(1, 3);
  Complex c2(2, 4);

  std::cout << (c1 < c2) << std::endl;

  return 0;
}

