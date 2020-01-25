// https://open.kattis.com/problems/ornaments
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int r, h, s;
    while (true) {
        scanf("%d %d %d", &r, &h, &s);
        if (r == 0 && h == 0 && s == 0) {
            break;
        }
        double l =
                2.0 * r * asin(r * 1.0 / h) + M_PI * r +
                2.0 * sqrt(h * h - r * r);
        printf("%.2lf\n", l * (1 + s / 100.0));
    }

    return 0;
}
