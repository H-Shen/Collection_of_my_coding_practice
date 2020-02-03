// https://open.kattis.com/problems/justaminute
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-7;
inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main() {

    int n, x, y;
    int minutes = 0;
    int minutes_ = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &x, &y);
        minutes += y;
        minutes_ += x;
    }
    double result = minutes * 1.0 / (minutes_ * 60.0);
    if (sgn(result - 1.0) <= 0) {
        printf("measurement error\n");
    } else {
        printf("%.8lf\n", result);
    }

    return 0;
}
