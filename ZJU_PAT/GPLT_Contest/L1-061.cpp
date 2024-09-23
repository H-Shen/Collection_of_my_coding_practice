#include <bits/stdc++.h>

using namespace std;
constexpr double EPS = 1e-8;

inline
auto f(double a) {
    if (a < -EPS) return -1;
    if (a < EPS) return 0;
    return 1;
}

int main() {

    double a, b, c;
    cin >> a >> b;
    c = a / (b * b);
    printf("%.1lf\n", c);
    if (f(c - 25.0) > 0) {
        cout << "PANG";
    } else {
        cout << "Hai Xing";
    }
    cout << endl;

    return 0;
}