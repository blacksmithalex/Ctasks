#include <iostream>
class Matrix {
public:
    Matrix(int r, int c) : numRows(r), numCols(c) {
        data = new double[r * c]();
    }

    Matrix(const double* d, int r, int c) : numRows(r), numCols(c) {
        data = new double[r * c];
        for (int i = 0; i < r * c; i++) data[i] = d[i];
    }

    Matrix(const Matrix& o) : numRows(o.numRows), numCols(o.numCols) {
        data = new double[numRows * numCols];
        for (int i = 0; i < numRows * numCols; i++) data[i] = o.data[i];
    }

    ~Matrix() { delete[] data; }

    double operator()(int i, int j) const {
        return data[i * numCols + j];
    }

    double& operator()(int i, int j) {
        return data[i * numCols + j];
    }

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

int main(){
    double* arr1 = new double[6]{1.0, 5.0, 7.0, -1.0, 2.0, 10.0}; 
    
    Matrix m1(arr1, 2, 3);
    m1.Print();
    std::cout << m1(0, 1) << std::endl;
    std::cout << m1(1, 2) << std::endl;

    delete[] arr1; 
    return 0;
}
