#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
typedef long double ld;

ll multmod(ll a, ll b, ll m) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return ((a*b -(ll)((ld)a/m*b)*m)%m+m)%m;
}

ll powmod(ll a, ll b, ll m) {
    if (m == 1) return 0; ll r{};
    for (r = 1, a %= m; b; a = multmod(a,a,m), b >>= 1) if (b % 2) r = multmod(r,a,m);
    return r;
}

int main() {
    ll b, p, k;
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld\n", b, p, k, powmod(b, p, k));
    return 0;
}

