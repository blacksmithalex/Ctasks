class Zk {
public:
    Zk(int v, int m) : value((v % m + m) % m), modulus(m) {}

    Zk operator+(int x) const {
        return Zk(value + x, modulus);
    }

    Zk operator*(int x) const {
        return Zk(value * x, modulus);
    }

    int value, modulus;
};
