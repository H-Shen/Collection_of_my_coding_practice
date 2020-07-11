#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-7;

int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main(int argc, char *argv[]) {

    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    // Case 1: a = 0
    if (sgn(a) == 0) {
        // Sub-case 1: b = 0, c = 0
        if (sgn(b) == 0 && sgn(c) == 0) {
            printf("-1\n");
        }
        // Sub-case 2: b = 0, c != 0
        else if (sgn(b) == 0 && sgn(c) != 0) {
            printf("0\n");
        }
        // Sub-case 3: b != 0
        else {
            printf("1\n");
            printf("%.6lf\n", -c / b);
        }
    }
    // Case 2: a != 0
    else {
        double delta = b * b - 4 * a * c;
        // Sub-case 1: delta = 0
        if (sgn(delta) == 0) {
            printf("1\n");
            printf("%.6lf\n", -b / (2 * a));
        }
        // Sub-case 2: delta > 0
        else if (sgn(delta) > 0) {
            printf("2\n");
            double x0 = (-b + sqrt(delta)) / (2 * a);
            double x1 = (-b - sqrt(delta)) / (2 * a);
            if (x0 > x1) {
                swap(x0, x1);
            }
            printf("%.6lf\n%.6lf\n", x0, x1);
        }
        // Sub-case 3: delta < 0
        else {
            printf("0\n");
        }
    }

    return 0;
}