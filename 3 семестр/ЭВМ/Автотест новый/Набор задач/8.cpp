#include <iostream>

class BinaryCounter {
public:
    BinaryCounter() : count(1) {
        data = new int[1]{0};
    }
    BinaryCounter(int* d, int c) : count(c){
        data = new int[c];
        for (int i = 0; i < c; i++) data[i] = d[i];
    }

    BinaryCounter(const BinaryCounter& other) = delete;
    ~BinaryCounter() { delete[] data; }

    BinaryCounter& operator=(const BinaryCounter& other) {
        if (this == &other) return *this;

        delete[] data;          
        count = other.count;     
        data = new int[count]; 

        for (int i = 0; i < count; i++)
            data[i] = other.data[i];

        return *this;
    }

    void Print() const {
        for (int i = count - 1; i >= 0; i--)
            std::cout << data[i];
        std::cout << "\n";
    }

private:
    int* data;
    int count;
};

int main() {
    BinaryCounter a;

    std::cout << "a = ";
    a.Print();

    BinaryCounter b;
    b = a;       

    std::cout << "b = ";
    b.Print();

    int arr1[] = {1, 0, 1, 1};
    BinaryCounter c(arr1, 4);
    std::cout << "c = ";
    c.Print();

    return 0;
}
