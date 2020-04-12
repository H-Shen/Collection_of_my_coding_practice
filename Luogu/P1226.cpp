#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
bool isPrime(ll n) {
    if (n <= 1) {
        return false;
    }
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Calculate (a^n) % m (n >= 0, m > 0) in O(lgn) without recursion
inline static
ll quickPower(ll a, ll n, ll m) {

    if (m == 1) {
        return 0;
    }

    // If m is a prime, then (a^n) % m = a^(n % (m - 1)) % m (Fermat's little theorem)
    if (isPrime(m)) {
        n = n % (m - 1);
    }

    a %= m;
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

int main() {

    ll b, p, k;
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld\n", b, p, k, quickPower(b, p, k));

    return 0;
}

