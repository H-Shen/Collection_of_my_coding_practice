// https://www.nowcoder.com/practice/7da524bb452441b2af7e64545c38dc26
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;
constexpr double eps = 1e-7;

int sgn(const double &x) {
    if (x > eps) return 1;
    if (x > -eps) return 0;
    return -1;
}

int main() {

    double a, b, c, delta, x1, x2, x1_real, x1_img, x2_real, x2_img;
    while (~scanf("%lf %lf %lf", &a, &b, &c)) {
        if (sgn(a) == 0) {
            printf("Not quadratic equation\n");
            continue;
        }
        delta = b * b - 4 * a * c;
        if (sgn(delta) == 0) {
            x1 = -b / (2 * a);
            x2 = x1;
            if (sgn(x1) == 0) {
                x1 = 0.0;
            }
            if (sgn(x2) == 0) {
                x2 = 0.0;
            }
            printf("x1=x2=%.2lf\n", x1);
        } else if (sgn(delta) > 0) {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            if (sgn(x1) == 0) {
                x1 = 0.0;
            }
            if (sgn(x2) == 0) {
                x2 = 0.0;
            }
            if (sgn(x1 - x2) > 0) {
                swap(x1, x2);
            }
            printf("x1=%.2lf;x2=%.2lf\n", x1, x2);
        } else {
            x1_real = -b / (2 * a);
            x1_img = -sqrt(-delta) / (2 * a);
            x2_real = x1_real;
            x2_img = sqrt(-delta) / (2 * a);

            if (sgn(x1_real) == 0) {
                x1_real = 0.0;
            }
            if (sgn(x1_img) == 0) {
                x1_img = 0.0;
            }
            if (sgn(x2_real) == 0) {
                x2_real = 0.0;
            }
            if (sgn(x2_img) == 0) {
                x2_img = 0;
            }

            printf("x1=%.2lf", x1_real);
            if (sgn(x1_img) < 0) {
                printf("%.2lfi", x1_img);
            } else {
                printf("+%.2lfi", x1_img);
            }
            printf(";");
            printf("x2=%.2lf", x2_real);
            if (sgn(x2_img) < 0) {
                printf("%.2lfi", x2_img);
            } else {
                printf("+%.2lfi", x2_img);
            }
            printf("\n");
        }
    }

    return 0;
}