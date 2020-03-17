// https://open.kattis.com/problems/nine
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr ll MOD = 1000000007;

// a(n) = 8*9^(n-1)
// a(n) % M = (8*9^(n-1)) % M = (8 % M) (9^(n-1) % M) % M

// Calculate (a^n) % m (n >= 0, m > 0) in O(lgn) without recursion
inline static
ll quickPower(ll a, ll n, ll m) {

    // Corner case:
    if (m == 1) {
        return 0;
    }

    n = n % (m - 1);
    a %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

inline static
ll solve(ll n) {
    return (8 % MOD) * quickPower(9, n - 1, MOD) % MOD;
}

int main() {

    int t;
    ll n;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        printf("%lld\n", solve(n));
    }

    return 0;
}
