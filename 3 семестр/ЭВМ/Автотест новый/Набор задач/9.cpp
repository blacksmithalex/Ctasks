#include <iostream>
class Zk {
public:
    Zk(int v, int m) : value((v % m + m) % m), modulus(m) {}

    Zk operator+(int x) const {
        return Zk(value + x, modulus);
    }

    Zk operator*(int x) const {
        return Zk(value * x, modulus);
    }
    
    void Print() const {
        std::cout << value << " (mod " << modulus << ")" << std::endl;
    }

    int value, modulus;
};

int main(){
    Zk num1 = Zk(7, 5);
    num1 = num1 * 4;
    num1.Print();
    num1 = num1 + 2;
    num1.Print();
    return 0;
}
