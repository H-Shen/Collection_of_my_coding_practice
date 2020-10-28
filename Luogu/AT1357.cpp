#include <iostream>

using namespace std;
using ll = long long;

inline static
ll modpow(ll a, ll p, ll M) {
    if (M == 1) return 0;
    ll r;
    for (r = 1, a %= M; p; a = (a * a) % M, p >>= 1) if (p % 2) r = (r * a) % M;
    return r;
}

int main() {

    ll n, m, p;
    cin >> n >> m >> p;
    cout << modpow(n, p, m) << '\n';

    return 0;
}