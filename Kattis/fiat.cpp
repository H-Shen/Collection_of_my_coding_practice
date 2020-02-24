// https://open.kattis.com/problems/fiat
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MOD = 1000000007;
constexpr ll MAXN =100050;

ll inv[MAXN];
ll Catalan[MAXN];

/*
Catalan[1] = 1, Catalan[2] = 1
Catalan[n] = (4n-2)/(n+1) * Catalan[n-1]
Catalan[n+1] = (4n+2)/(n+2) * Catalan[n]
Catalan[n+1] % p
= ((4n+2)/(n+2) * Catalan[n]) % p
= ((4n+2)Catalan[n] * inv[n+2]) % p
= ((4n+2)Catalan[n] %p * inv[n+2] % p) % p
*/

int main() {

    // Obtain inverse of p from 1 to MAXN
    inv[1] = 1;
    for (ll i = 2; i <= MAXN; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }

    // Obtain Catalan[n] % p
    Catalan[0] = 1;
    Catalan[1] = 1;
    ll n;
    scanf("%lld", &n);
    for (ll i = 2; i <= n; ++i) {
        // Catalan[i] = (4*i-2)*Catalan[i-1] / (i+1);
        Catalan[i] = (4*i-2)*Catalan[i-1] % MOD * inv[i+1] % MOD;
    }
    printf("%lld\n", Catalan[n]);
    return 0;
}
