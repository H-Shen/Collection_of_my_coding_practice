// https://open.kattis.com/problems/billiard
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll a, b, s, m, n;
    while (true) {
        scanf("%lld %lld %lld %lld %lld", &a, &b, &s, &m, &n);
        if (a == 0 && b == 0 && s == 0 && m == 0 && n == 0) {
            break;
        }
        double A = 180.0 * atan2(static_cast<double>(n * b) * 1.0,
                                 static_cast<double>(m * a) * 1.0) / M_PI;
        double t = sqrt((m * a) * (m * a) + (b * n) * (b * n)) / s;
        printf("%.2lf %.2lf\n", A, t);
    }
    return 0;
}
