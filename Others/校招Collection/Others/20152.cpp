#include <bits/stdc++.h>

using namespace std;

struct A {
    int n;

    A() {};

    A(int n_) : n(n_) {}

    A operator+(A other) const {
        A res(n + other.n);
        return res;
    }
};

int main() {
    A c;
    const A a(10);
    c = a + A(30);
    assert(c.n == 40);
    return 0;
}