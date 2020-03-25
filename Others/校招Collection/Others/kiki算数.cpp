// https://www.nowcoder.com/practice/bcaf710fb58a44e1b678a890e6e90d7c
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a >= 100) {
            a %= 100;
        }
        if (b >= 100) {
            b %= 100;
        }
        int c = a + b;
        if (c >= 100) {
            c %= 100;
        }
        cout << c << endl;
    }
    return 0;
}