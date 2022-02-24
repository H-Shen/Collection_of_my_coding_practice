// https://open.kattis.com/problems/ghostbusters3

#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr ll MAXN = 1005;
constexpr ll MOD = 1e9+7;
ll fact[MAXN];

void exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

ll inv(ll n) {
    ll x{}, y{};
    exgcd(n, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    return x;
}

void pre() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i-1] * i % MOD;
    }
}

ll comb(ll n, ll k) {
    return fact[n] * inv(fact[k] * fact[n - k] % MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    ll n, m;
    cin >> n >> m;
    if (m >= n) {
        cout << comb(m, n) << '\n';
    }
    else {
        cout << comb(n-1,m-1) << '\n';
    }
    return 0;
}
