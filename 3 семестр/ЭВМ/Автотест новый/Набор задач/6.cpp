#include <iostream>

class Matrix {
public:
    Matrix(const double* d, int r, int c) : numRows(r), numCols(c) {
        data = new double[r * c];
        for (int i = 0; i < r * c; i++) data[i] = d[i];
    }

    Matrix(const Matrix& o) : numRows(o.numRows), numCols(o.numCols) {
        data = new double[numRows * numCols];
        for (int i = 0; i < numRows * numCols; i++) data[i] = o.data[i];
    }

    Matrix& operator=(const Matrix& o) {
        if (this != &o) {
            delete[] data;
            numRows = o.numRows;
            numCols = o.numCols;
            data = new double[numRows * numCols];
            for (int i = 0; i < numRows * numCols; i++) data[i] = o.data[i];
        }
        return *this;
    }

    ~Matrix() { delete[] data; }

    void Print() const {
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++)
                std::cout << data[i*numCols + j] << " ";
            std::cout << "\n";
        }
    }

private:
    double* data;
    int numRows, numCols;
};
