#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int CERTAINTY = 5;
const int NOT_EXIST = 404;

ll mult_mod(ll a, ll b, ll c) {
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

ll pow_mod(ll x, ll n, ll mod) {
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

bool isProbablePrimeHelper(ll a, ll n, ll x, ll t) {
    ll result = pow_mod(a, x, n);
    ll last = result;
    for (int i = 1; i <= t; i++) {
        result = mult_mod(result, result, n);
        if (result == 1 && last != 1 && last != n - 1)
            return true;
        last = result;
    }
    return (result != 1);
}

bool isProbablePrime(ll n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if ((n & 1) == 0)
        return false;

    ll x = n - 1;
    ll t = 0;
    while ((x & 1) == 0) {
        x >>= 1;
        t++;
    }
    for (int i = 0; i < CERTAINTY; i++) {
        ll a = rand() % (n - 1) + 1;
        if (isProbablePrimeHelper(a, n, x, t))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    string L, substring;
    cin >> N >> K >> L;
    int len = static_cast<int>(L.size());

    for (int i = 0; i + K <= len; ++i) {
        substring = L.substr(i, K);
        if (isProbablePrime(stol(substring))) {
            cout << substring << endl;
            return 0;
        }
    }
    cout << NOT_EXIST << endl;
    return 0;
}