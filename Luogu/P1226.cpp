#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
ll modpow(ll a, ll p, ll M) {
    if (M == 1) return 0;
    ll r;
    for (r = 1, a %= M; p; a = (a * a) % M, p >>= 1) if (p % 2) r = (r * a) % M;
    return r;
}


int main() {
    ll b, p, k;
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld\n", b, p, k, modpow(b, p, k));
    return 0;
}

