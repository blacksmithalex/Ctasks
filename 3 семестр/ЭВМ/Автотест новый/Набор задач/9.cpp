#include <iostream>
class Zk {
public:
    Zk(int v, int m) : value((v % m + m) % m), modulus(m) {}

    Zk operator+(int x) const {
        return Zk(value + x, modulus);
    }

    Zk operator-(int x) const {
        return Zk(value - x, modulus);
    }

    Zk operator*(int x) const {
        return Zk(value * x, modulus);
    }

    Zk operator^(int deg) const{
        Zk res = Zk(1, modulus);
        for (int i = 0; i < deg; i++)
            res = Zk(res.value * value, modulus);
        return res;
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
    num1 = num1 - 37;
    num1.Print();
    Zk num2 = Zk(3, 7);
    Zk num3 = num2^4;
    num3.Print();
    return 0;
}
