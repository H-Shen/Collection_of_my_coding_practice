// https://open.kattis.com/problems/differentdistances
#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

inline
bool is_zero(double a) {
    if (a > eps) return false;
    if (a < -eps) return false;
    return true;
}

int main() {

    double x1, y1, x2, y2, p;
    while (true) {
        scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &p);

        if (is_zero(x1)) break;

        double result = pow(pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p), 1.0 / p);
        printf("%.4lf\n", result);
    }

    return 0;
}
