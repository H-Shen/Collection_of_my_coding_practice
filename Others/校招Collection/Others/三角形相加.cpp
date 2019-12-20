// https://www.nowcoder.com/practice/cb867ebc313f480cbbf0a1b334d3a1fc

#include <iostream>

using namespace std;
using ll = long long;

class CTriangle {
private:
    static ll y, x;
public:
    static void Add(ll y_, ll x_) {
        y += y_;
        x += x_;
    }

    explicit CTriangle() = default;

    ~CTriangle() {
        cout << "A(0," << y;
        cout << "),B(0,0),C(";
        cout << x << ",0)" << endl;
    }
};

ll CTriangle::y, CTriangle::x;

int main() {

    ll y, x;
    auto object = new CTriangle();
    while (cin >> y) {
        if (y == 0) {
            break;
        }
        cin >> x;
        CTriangle::Add(y, x);
    }
    delete object;

    return 0;
}