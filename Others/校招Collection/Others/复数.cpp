// https://www.nowcoder.com/practice/743667f48c4d49a59b7b0613b8aa1c11

#include <iostream>

using namespace std;

class Complex {
private:
    int a, b;
public:
    Complex() : a(0), b(0) {}

    Complex operator+(Complex const &obj) {
        Complex result;
        result.a = a + obj.a;
        result.b = b + obj.b;
        return result;
    }

    friend ostream &operator<<(ostream &out, const Complex &object);

    friend istream &operator>>(istream &in, Complex &object);
};

ostream &operator<<(ostream &out, const Complex &object) {
    out << object.a;
    if (object.b != 0) {
        if (object.b > 0) {
            out << "+";
        }
        out << object.b << "i";
    }
    return out;
}

istream &operator>>(istream &in, Complex &object) {
    in >> object.a >> object.b;
    return in;
}

int main() {

    int m;
    cin >> m;
    while (m--) {
        Complex obj0, obj1;
        cin >> obj0 >> obj1;
        obj0 = obj0 + obj1;
        cout << obj0 << endl;
    }

    return 0;
}