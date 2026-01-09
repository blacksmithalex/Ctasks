#include <iostream>

class Complex {
public:
    Complex(double re, double im = 0) : re(re), im(im) {}

    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.re << (c.im >= 0 ? " + " : " - ") << std::abs(c.im) << "i";
        return out;
    }

private:
    double re, im;
};

int main() {
    Complex a(3, 4), b(1, -2);
    std::cout << a + b << std::endl;
}
