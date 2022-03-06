using ll = long long;
using ld = long double;

constexpr ll M = 1e9+7;

// O(1) modulo mul
ll multmod(ll a, ll b, ll m) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return ((a * b - (ll)((ld)(a) / m * b) * m) %
            m + m) % m;
}

// O(logb), better version
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
    // a(n) = (2n)!/2^n
    // 因为 gcd(2^n, M) = 1, 由费马小定理 有
    // ((2n)!/2^n) % M = ((2n)!*2^(n(M-2))) % M
    // = ((2n)! % M) * (2^(n(M-2)) % M) % M
    int countOrders(int n) {
        ll left = 1; 
        for (ll i = 1, j = 2*n; i <= j; ++i) {
            left = (left * i) % M;
        }
        ll right = powmod(2, n*(M-2), M);
        return (int)(left * right % M);
    }
};