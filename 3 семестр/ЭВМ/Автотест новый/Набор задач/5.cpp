#include <cstring>
#include <iostream>

class String {
public:
    String(const char* s) {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    ~String() { delete[] data; }

    char& operator[](int i) { return data[i]; }
    const char& operator[](int i) const { return data[i]; }

    friend std::ostream& operator<<(std::ostream& out, const String& s) {
        return out << s.data;
    }

    char* data;
};

int main() {
    String str1("abcd");
    std::cout << str1[2] << std::endl;
    str1[2] = 'L';
    std::cout << str1[2] << std::endl;
    const String str2("klmn");
    std::cout << str2[2] << std::endl;
    return 0;
}
