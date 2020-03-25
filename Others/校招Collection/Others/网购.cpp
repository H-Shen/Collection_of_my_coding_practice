// https://www.nowcoder.com/practice/5d7dfd405e5f4e4fbfdff6862c46b751
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
    double price;
    int month;
    int day;
    int has_coupon;
    scanf("%lf %d %d %d", &price, &month, &day, &has_coupon);
    if (month == 11 && day == 11) {
        if (has_coupon) {
            price = 0.7 * price - 50.0;
        } else {
            price = 0.7 * price;
        }
    }
    else if (month == 12 && day == 12) {
        if (has_coupon) {
            price = 0.8 * price - 50.0;
        } else {
            price = 0.8 * price;
        }
    }
    if (sgn(price) < 0) {
        price = 0.0;
    }
    printf("%.2lf\n", price);
    return 0;
}