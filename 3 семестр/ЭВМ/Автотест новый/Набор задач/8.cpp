class BinaryCounter {
public:
    BinaryCounter() : count(1) {
        data = new int[1]{0};
    }

    ~BinaryCounter() { delete[] data; }

    BinaryCounter& operator++() {
        int i = 0;
        while (i < count && data[i] == 1) {
            data[i++] = 0;
        }
        if (i == count) {
            int* nd = new int[count + 1]{};
            for (int j = 0; j < count; j++) nd[j] = data[j];
            delete[] data;
            data = nd;
            data[count++] = 1;
        } else data[i] = 1;
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
