// https://www.nowcoder.com/practice/422f6341cf1b4212a7f8c703df111389
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    b /= 100.0;
    printf("%.2lf\n", a / (b * b));
    return 0;
}