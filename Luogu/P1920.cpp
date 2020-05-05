#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double EPS = 1e-8;
inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

inline static
double quickPower(double a, ll n) {
    double res = 1.0;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

int main() {

    double x;
    ll n;
    scanf("%lf %lld", &x, &n);
    double last = -1.0;
    double sum = 0.0;
    for (ll i = 1; i <= n; ++i) {
        sum += quickPower(x, i) / static_cast<double>(i);
        if (sgn(sum - last) == 0) {
            break;
        }
        last = sum;
    }
    printf("%.4lf\n", sum);

    return 0;
}
