#include <stdio.h>

#define EPS (1e-6)

int sgn(double a) {
    if (a > EPS) {
        return 1;
    }
    if (a < -EPS) {
        return -1;
    }
    return 0;
}

int main() {
    int x;
    double y = 0.0;
    scanf("%d", &x);
    if (sgn(x - 15.0) == 1) {
        y = 2.5 * x - 17.5;
    } else {
        y = 4.0 * x / 3.0;
    }
    printf("%.2f\n", y);
    return 0;
}