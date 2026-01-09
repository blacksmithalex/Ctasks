Complex& operator+=(const Complex& other) {
    re += other.re;
    im += other.im;
    return *this;
}