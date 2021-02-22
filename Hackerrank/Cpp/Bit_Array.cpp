// https://www.hackerrank.com/challenges/bitset-1/problem

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 2147483648;
ll n, s, p, q;

ll f(ll x) {
    return (p*x % MOD+q % MOD) % MOD;
}

ll brent(ll x) {
    ll power = 1;
    ll lambda = 1;
    ll tortoise = x;
    ll hare = f(x);
    while (tortoise != hare) {
        if (power == lambda) {
            tortoise = hare;
            power *= 2;
            lambda = 0;
        }
        hare = f(hare);
        ++lambda;
        if (lambda > n) {
            return n;
        }
    }
    tortoise = x;
    hare = x;
    for (ll i = 0; i < lambda; ++i) {
        hare = f(hare);
    }
    ll mu = 0;
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        ++mu;
        if (lambda + mu > n) {
            return n;
        }
    }
    return lambda + mu;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> s >> p >> q;
    cout << brent(s % MOD) << '\n';


    return 0;
}
