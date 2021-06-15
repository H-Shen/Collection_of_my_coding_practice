// https://open.kattis.com/problems/bootstrappingnumber

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {
    double l = 1.0;
    double r = 10.0;
    double mid;
    double n;
    scanf("%lf", &n);
    constexpr double EPS = 1e-8;
    while (r - l > EPS) {
        mid = (l + r) / 2.0;
        if (pow(mid, mid) >= n) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    printf("%.7lf\n", l);
    return 0;
}
