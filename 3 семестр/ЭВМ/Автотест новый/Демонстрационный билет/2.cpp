#include <iostream>

class Complex {
public:
    Complex(double re, double im = 0) : re(re), im(im) {}

    // Перегрузка оператора +
    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    void print() const {
        std::cout << re;
        if (im >= 0) std::cout << " + ";
        else std::cout << " - ";
        std::cout << std::abs(im) << "i\n";
    }

private:
    double re;
    double im;
};

int main() {
    Complex a(3, 4);
    Complex b(1, -2);

    Complex c = a + b;

    std::cout << "a = "; a.print();
    std::cout << "b = "; b.print();
    std::cout << "a + b = "; c.print();

    return 0;
}
