// https://www.nowcoder.com/practice/08b28e61ff6345febf09969b3a167f7e
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;
constexpr double eps = 1e-7;
inline static
int sgn(const double &x) {
    if (x > eps) return 1;
    if (x > -eps) return 0;
    return -1;
}

int main() {
    double a, b, bmi;
    scanf("%lf %lf", &a, &b);
    bmi = a / (b * b);
    if (sgn(bmi - 18.5) >= 0 && sgn(bmi - 23.9) <= 0) {
        printf("Normal\n");
    } else {
        printf("Abnormal\n");
    }
    return 0;
}