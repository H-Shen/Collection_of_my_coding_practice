#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

int sgn(double a) {
    if (a < -eps)
        return -1;
    if (a < eps)
        return 0;
    return 1;
}

int main() {
    int n, d;
    double e;
    scanf("%d %lf %d", &n, &e, &d);
    int i, j, days;
    int cnt0 = 0, cnt1 = 0;
    double tmp;
    int cnt;

    for (i = 0; i < n; ++i) {
        scanf("%d", &days);
        cnt = 0;
        if (days > d) {
            for (j = 0; j < days; ++j) {
                scanf("%lf", &tmp);
                if (sgn(tmp - e) < 0) {
                    ++cnt;
                }
            }
            if (cnt > days / 2) {
                ++cnt1;
            }
        } else {
            for (j = 0; j < days; ++j) {
                scanf("%lf", &tmp);
                if (sgn(tmp - e) < 0) {
                    ++cnt;
                }
            }
            if (cnt > days / 2) {
                ++cnt0;
            }
        }
    }
    double res0 = (double) cnt0 / n * 100.0;
    double res1 = (double) cnt1 / n * 100.0;
    char per = '%';
    printf("%.1lf%c %.1lf%c", res0, per, res1, per);
    putchar('\n');
    return 0;
}