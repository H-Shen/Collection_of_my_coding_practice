// https://open.kattis.com/problems/conteststruggles

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int sgn(const double &x) {
    static const double EPS = 1e-7;
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main() {

    int n, k, d, s;
    cin >> n >> k >> d >> s;
    double avg = (d*n - s*k) * 1.0 / (n-k);
    if (sgn(avg) < 0 || sgn(avg - 100.0) > 0) {
        printf("impossible\n");
    } else {
        printf("%.7lf\n", avg);
    }
    
    return 0;
}
