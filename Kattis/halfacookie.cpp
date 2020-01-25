// https://open.kattis.com/problems/halfacookie
//
#include <bits/extc++.h>

using namespace std;

inline static
int sgn(const double &x) {
    double eps = 1e-8;
    if (x > eps) {
        return 1;
    }
    if (x > -eps) {
        return 0;
    }
    return -1;
}

int main() {

    double r, x, y, s, theta, circular_sector, triangle_square, a_big, a_small;
    while (~scanf("%lf %lf %lf", &r, &x, &y)) {
        s = x * x + y * y;
        if (sgn(s - r * r) > 0) {
            printf("miss\n");
        } else {
            theta = acos((4 * s - 2 * r * r) / (2 * r * r));
            circular_sector = theta * r * r / 2;
            triangle_square = sqrt(r * r - s) * sqrt(s);
            a_small = circular_sector - triangle_square;
            a_big = M_PI * r * r - a_small;
            printf("%.6lf %.6lf\n", a_big, a_small);
        }
    }

    return 0;
}
