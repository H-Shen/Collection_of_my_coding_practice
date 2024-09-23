#include <bits/stdc++.h>

using namespace std;

const double EPS1 = 1e-2;

int main() {
    double R0, P0, R1, P1;
    scanf("%lf %lf %lf %lf", &R0, &P0, &R1, &P1);

    double real = R0 * R1 * cos(P0 + P1);
    double image = R0 * R1 * sin(P0 + P1);

    bool imageIsNegative = true;
    if (image > EPS1 || fabs(image) < EPS1) {
        imageIsNegative = false;
    }

    if (fabs(real) < EPS1) {
        real = 0;
    }
    if (fabs(image) < EPS1) {
        image = 0;
    }

    if (imageIsNegative) {
        printf("%.2lf-%.2lfi\n", real, fabs(image));
    } else {
        printf("%.2lf+%.2lfi\n", real, image);
    }
    return 0;
}