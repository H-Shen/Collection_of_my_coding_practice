// https://open.kattis.com/problems/fundamentalneighbors
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

// O(logn)
ll power(ll a, ll n) {
    if (n == 0 || a == 1) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

int main() {

    ll n, n_copy;
    while (~scanf("%lld", &n)) {
        unordered_map<ll, ll> unmap;
        n_copy = n;
        for (ll i = 2; i * i <= n; ++i) {   // remember not i * i <= n_copy here!
            while (n % i == 0) {
                ++unmap[i];
                n /= i;
            }
        }
        // Just in case if a biggest prime left
        if (n > 1) {
            ++unmap[n];
        }
        ll sum = 1;
        for (const auto &[k, v] : unmap) {
            sum *= power(v, k);
        }
        printf("%lld %lld\n", n_copy, sum);
    }

    return 0;
}
