// https://open.kattis.com/problems/matrix
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    ll a, b, c, d, det, a_new, b_new, c_new, d_new;
    int kase = 1;
    while (~scanf("%lld %lld", &a, &b)) {
        scanf("%lld %lld", &c, &d);
        det = a * d - b * c;
        a_new = d / det;
        b_new = -b / det;
        c_new = -c / det;
        d_new = a / det;
        printf("Case %d:\n", kase);
        printf("%lld %lld\n%lld %lld\n", a_new, b_new, c_new, d_new);
        ++kase;
    }

    return 0;
}
