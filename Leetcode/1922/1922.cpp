using ll = long long;

ll multmod(ll a, ll b, ll m) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return ((a * b - (ll)((long double)(a) / m * b) * m) %
            m + m) % m;
}

ll powmod(ll a, ll b, ll m) {
    if (m == 1) return 0;
    ll r;
    for (r = 1, a %= m; b; a = multmod(a, a, m), b >>= 1) {
        if (b % 2) r = multmod(r, a, m);
    }
    return r;
}

class Solution {
public:
    int countGoodNumbers(long long n) {
        constexpr ll MOD = 1e9+7;
        if (!(n & 1)) {
            return (int)multmod(powmod(4, n>>1, MOD), powmod(5, n>>1, MOD), MOD);
        }
        return (int)multmod(powmod(4, (n-1)>>1, MOD), powmod(5, (n+1)>>1, MOD), MOD);
    }
};