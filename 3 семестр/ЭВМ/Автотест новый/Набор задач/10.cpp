class Decimal {
public:
    Decimal(int* d, int c) : count(c) {
        digits = new int[c];
        for (int i = 0; i < c; i++) digits[i] = d[i];
    }

    Decimal(const Decimal& o) : count(o.count) {
        digits = new int[count];
        for (int i = 0; i < count; i++) digits[i] = o.digits[i];
    }

    Decimal& operator=(const Decimal& o) {
        if (this != &o) {
            delete[] digits;
            count = o.count;
            digits = new int[count];
            for (int i = 0; i < count; i++) digits[i] = o.digits[i];
        }
        return *this;
    }

    ~Decimal() { delete[] digits; }

    Decimal operator+(const Decimal& o) const {
        int carry = 0;
        int n = std::max(count, o.count);
        int* r = new int[n + 1]{};

        for (int i = 0; i < n; i++) {
            int s = carry;
            if (i < count) s += digits[i];
            if (i < o.count) s += o.digits[i];
            r[i] = s % 10;
            carry = s / 10;
        }
        if (carry) r[n++] = carry;
        return Decimal(r, n);
    }

    int* digits;
    int count;
};
