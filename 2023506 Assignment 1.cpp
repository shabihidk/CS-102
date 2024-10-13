#include <iostream>
#include <cstring>

using namespace std;

class Strinx {
private:
    char* str;
    int len;
    int size;

public:
    Strinx() {
        size = 50;
        str = new char[size];
        len = 0;
    }

    Strinx(int s) {
        size = s;
        str = new char[size];
        len = 0;
    }

    Strinx(const char* arr) {
        size = strlen(arr) + 1;
        str = new char[size];
        strcpy(str, arr);
        len = strlen(str);
    }

    ~Strinx() {
        delete[] str;
    }

    int getLength() const {
        return len;
    }

    int getSize() const {
        return size;
    }

    Strinx operator+(const Strinx& other) const {
        Strinx result(size + other.size - 1);
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    Strinx& operator+=(const Strinx& other) {
        int newLen = len + other.len;
        if (newLen >= size) {
            char* temp = new char[newLen + 1];
            strcpy(temp, str);
            strcat(temp, other.str);
            delete[] str;
            str = temp;
            size = newLen + 1;
        } else {
            strcat(str, other.str);
        }
        len = newLen;
        return *this;
    }

    char& operator[](int index) const {
        if (index < 0 || index >= len) {
            cerr << "Index out of bounds\n";
            exit(1);
        }
        return str[index];
    }

    bool operator==(const Strinx& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const Strinx& other) const {
        return strcmp(str, other.str) != 0;
    }

    bool operator>(const Strinx& other) const {
        return strcmp(str, other.str) > 0;
    }

    bool operator<(const Strinx& other) const {
        return strcmp(str, other.str) < 0;
    }

    Strinx operator()(int start, int length) const {
        if (start < 0 || start >= len || length < 0 || start + length > len) {
            cerr << "Invalid sub-string parameters\n";
            exit(1);
        }
        return Strinx(str + start);
    }

    friend ostream& operator<<(ostream& os, const Strinx& strx) {
        os << strx.str;
        return os;
    }

    Strinx operator<<(int shift) const {
        if (shift >= len) {
            cerr << "Invalid left shift\n";
            exit(1);
        }
        return Strinx(str + shift);
    }

    Strinx operator>>(int shift) const {
        if (shift >= len) {
            cerr << "Invalid right shift\n";
            exit(1);
        }
        return Strinx(str + (len - shift));
    }
};

int main() {
    Strinx a("Name");
    Strinx b(" Shabih");

    Strinx c = a + b;
    cout << "Concatenation using + operator: " << c << endl;

    a += b;
    cout << "Concatenation using += operator: " << a << endl;

    cout << "Character at index 1: " << a[1] << endl;

    cout << "String equality test: " << (a == b ? "Equal" : "Not equal") << endl;

    cout << "String inequality test: " << (a != b ? "Not equal" : "Equal") << endl;

    cout << "String comparison test (a > b): " << (a > b ? "a is greater than b" : "a is not greater than b") << endl;
    cout << "String comparison test (a < b): " << (a < b ? "a is less than b" : "a is not less than b") << endl;

    Strinx sub = a(1, 3);
    cout << "Sub-string (1, 3): " << sub << endl;

    cout << "Printing using ostream: " << a << endl;

    Strinx leftShift = a << 2;
    cout << "String left shift (2): " << leftShift << endl;

    Strinx rightShift = a >> 2;
    cout << "String right shift (2): " << rightShift << endl;

    return 0;
}


