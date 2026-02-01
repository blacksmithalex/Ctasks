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
    int numRows;
    int numCols;
};

int main(){
    double* arr1 = new double[6]{1.0, 5.0, 7.0, -1.0, 2.0, 10.0}; 
    
    Matrix m1(arr1, 2, 3);
    Matrix m2(m1);
    m1.Print();
    m2.Print();

    delete[] arr1; 
    return 0;
}