#include <cstring>
#include <iostream>

class String {
public:
    String(const char* s) {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    ~String() { delete[] data; }

    String operator+(const String& other) const {
        char* buf = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(buf, data);
        strcat(buf, other.data);
        String res(buf);
        delete[] buf;
        return res;
    }

    friend std::ostream& operator<<(std::ostream& out, const String& s) {
        return out << s.data;
    }

    char* data;
};
