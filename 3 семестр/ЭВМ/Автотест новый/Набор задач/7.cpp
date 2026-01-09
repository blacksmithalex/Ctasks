class Matrix {
public:
    Matrix(int r, int c) : numRows(r), numCols(c) {
        data = new double[r * c]();
    }

    ~Matrix() { delete[] data; }

    double operator()(int i, int j) const {
        return data[i * numCols + j];
    }

    double& operator()(int i, int j) {
        return data[i * numCols + j];
    }

private:
    double* data;
    int numRows, numCols;
};
