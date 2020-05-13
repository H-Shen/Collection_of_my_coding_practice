#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double EPS = 1e-7;
inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main() {
    int n, m;
    double a, b;
    double min_price = -1.0;
    scanf("%d %d", &n, &m);
    while (n--) {
        scanf("%lf %lf", &a, &b);
        if (min_price < 0.0) {
            min_price = a / b;
        } else {
            if (sgn(a / b - min_price) < 0) {
                min_price = a / b;
            }
        }
    }
    printf("%.8lf\n", min_price * m);
    return 0;
}