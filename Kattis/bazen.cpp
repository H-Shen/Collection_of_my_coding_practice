// https://open.kattis.com/problems/bazen
//
#include <bits/extc++.h>

using namespace std;

constexpr double EPS = 1e-8;

inline static
int sgn(const double &a) {
    if (a > EPS) {
        return 1;
    }
    if (a > -EPS) {
        return 0;
    }
    return -1;
}

int main() {

    double half_area = 250.0 * 250.0 / 4.0;
    int x, y;
    double x_d, y_d;
    double c, d;
    cin >> x >> y;
    x_d = x;
    y_d = y;

    if (x >= 0 && sgn(x_d - 125.5) <= 0 && y == 0) {
        d = half_area * 2.0 / (250.0 - x_d);
        c = 250.0 - d;
    }
    else if (x <= 250 && sgn(x_d - 125.5) > 0 && y == 0) {
        d = half_area * 2.0 / x_d;
        c = 0.0;
    }
    else if (x == 0 && y >= 0 && sgn(y_d - 125.5) <= 0) {
        c = half_area * 2.0 / (250.0 - y_d);
        d = -c + 250.0;
    }
    else if (x == 0 && y <= 250 && sgn(y_d - 125.5) > 0) {
        c = half_area * 2.0 / y_d;
        d = 0.0;
    }
    else if (y == -x + 250 && x > 0 && sgn(x_d - 125.5) <= 0) {
        c = 250.0 - half_area * 2.0 / y_d;
        d = 0.0;
    }
    else {
        c = 0.0;
        d = 250.0 - half_area * 2.0 / x_d;
    }
    printf("%.2lf %.2lf\n", c, d);

    return 0;
}
