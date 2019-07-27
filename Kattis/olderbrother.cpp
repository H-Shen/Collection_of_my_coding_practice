// https://open.kattis.com/problems/olderbrother

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 40003;
ll prime[N] = {0}, num_prime = 0;
ll isNotPrime[N] = {1, 1};

//linearSieve
void linearSieve() {
    for (ll i = 2; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (ll j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}

//millerRabinSieve
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
    for (int i = 0; i < s; i++) {
        ll a = rand() % (n - 1) + 1;
        if (millerRabinPrimeCheckHelper(a, n, x, t))
            return false;
    }
    return true;
}

bool checkPower(ll a, ll n, ll b) {
    ll res = 1;
    for (int i = 0; i < n; ++i) {
        res = res * a;
    }
    return (res == b);
}

int main(void) {
    linearSieve();
    ios_base::sync_with_stdio(false);
    ll n;

    ll maxPower = 0;
    cin >> n;

    if (n == 1) {
        cout << "no" << endl;
        return 0;
    } else if (n > 40000 && millerRabinPrimeCheck(n)) {
        cout << "yes" << endl;
        return 0;
    } else if (n < 40000 && isNotPrime[n] != 1) {
        cout << "Yes" << endl;
        return 0;
    } else {
        maxPower = log2(n);
        ++maxPower;
        ll tmp = 0;
        for (int i = maxPower; i >= 2; --i) {
            tmp = pow(n, 1.0 / i);
            if (checkPower(tmp, i, n) && isNotPrime[tmp] != 1) {
                cout << "yes" << endl;
                return 0;
            }
            if (checkPower(tmp - 1, i, n) && isNotPrime[tmp - 1] != 1) {
                cout << "yes" << endl;
                return 0;
            }
            if (checkPower(tmp + 1, i, n) && isNotPrime[tmp + 1] != 1) {
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;

    return 0;
}
