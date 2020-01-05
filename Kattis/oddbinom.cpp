// https://open.kattis.com/problems/oddbinom
//
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// https://oeis.org/A006046
// a(1) = 1, a(n) = 2*a(floor(n/2)) + a*(ceiling(n/2))
ll a(ll n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return 3 * a(n / 2);
    }
    return 2*a(n / 2) + a(n / 2 + 1);
}

int main() {

    ll n;
    scanf("%lld", &n);
    printf("%lld\n", a(n));

    return 0;
}
