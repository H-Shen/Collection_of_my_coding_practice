// https://ac.nowcoder.com/acm/contest/982/I

//Lucas定理求C(n, m) % p (p必须是素数)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll p = 10007;

ll n, m, fac[MAXN];

void init() {
    ll i;
    fac[0] = 1;
    for (i = 1; i <= p; i++)
        fac[i] = fac[i - 1] * i % p;
}

ll q_pow(ll a, ll b, ll p) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

ll Combination(ll n, ll m) {
    if (m > n)
        return 0;
    return fac[n] * q_pow(fac[m] * fac[n - m], p - 2, p) % p;
}

ll lucas(ll n, ll m, ll p) { // Combination(n, m) % p
    if (m == 0)
        return 1;
    return (Combination(n % p, m % p) * lucas(n / p, m / p, p)) % p;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        init();
        printf("%lld\n", lucas(n, m, p));
    }
    return 0;
}
