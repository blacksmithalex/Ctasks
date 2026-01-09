String& operator+=(const String& other) {
    char* buf = new char[strlen(data) + strlen(other.data) + 1];
    strcpy(buf, data);
    strcat(buf, other.data);
    delete[] data;
    data = buf;
    return *this;
}
