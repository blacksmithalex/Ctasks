#include <cstring>
#include <iostream>

class String {
public:
    String(const char* s) {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    ~String() { delete[] data; }

    String& operator+=(const String& other) {
        char* buf = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(buf, data);
        strcat(buf, other.data);
        delete[] data;
        data = buf;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const String& s) {
        return out << s.data;
    }

    char* data;
};

int main() {
    String str1("abcd");
    String str2("efg");
    str1 += str2;
    std::cout << str1 << std::endl;
    return 0;
}
