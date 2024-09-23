#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mult_mod(ll a, ll b, ll c) { // a * b % c
    a %= c;
    b %= c;
    ll result = 0;
    while (b > 0) {
        if (b & 1) {
            result += a;
            result %= c;
        }
        a <<= 1;
        if (a >= c)
            a %= c;
        b >>= 1;
    }
    return result;
}


ll pow_mod(ll x, ll n, ll mod) {  // x^n % c
    if (n == 1)
        return x % mod;
    x %= mod;
    ll tmp = x;
    ll result = 1;
    while (n > 0) {
        if ((n & 1) > 0)
            result = mult_mod(result, tmp, mod);
        tmp = mult_mod(tmp, tmp, mod);
        n >>= 1;
    }
    return result;
}

bool millerRabinPrimeCheckHelper(ll a, ll n, ll x, ll t) {
    ll result = pow_mod(a, x, n);
    ll last = result;
    for (int i = 1; i <= t; i++) {
        result = mult_mod(result, result, n);
        if (result == 1 && last != 1 && last != n - 1)
            return true;
        last = result;
    }
    if (result != 1)
        return true;
    return false;
}

bool millerRabinPrimeCheck(ll n) {
    const int s = 5;
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if ((n & 1) == 0)
        return false;

    ll x = n - 1;
    ll t = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        t++;
    }
    for (int i = 0; i < s; i++) {
        ll a = rand() % (n - 1) + 1;
        if (millerRabinPrimeCheckHelper(a, n, x, t))
            return false;
    }
    return true;
}

int main() {
    ll n;
    int cnt;
    cin >> cnt;
    while (cnt--) {
        cin >> n;
        if (millerRabinPrimeCheck(n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }
    return 0;
}