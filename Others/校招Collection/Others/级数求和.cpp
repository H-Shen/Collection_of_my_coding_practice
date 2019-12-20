// https://ac.nowcoder.com/acm/contest/230/A

#include <bits/stdc++.h>

using namespace std;
constexpr double eps = 1e-6;

inline static
int sgn(const double &a) {
    if (a > eps) {
        return 1;
    }
    if (a > -eps) {
        return 0;
    }
    return -1;
}

int main() {

    double k;
    scanf("%lf", &k);
    double s = 0.0;
    int i;
    for (i = 1; ; i += 2) {
        s += 1.0 / i;
        if (sgn(s - k) == 1) {
            break;
        }
        s += 1.0 / (i + 1);
        if (sgn(s - k) == 1) {
            i += 1;
            break;
        }
    }
    printf("%d\n", i);

    return 0;
}