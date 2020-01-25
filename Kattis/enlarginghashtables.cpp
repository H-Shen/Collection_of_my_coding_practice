// https://open.kattis.com/problems/enlarginghashtables
//
#include <bits/extc++.h>

using namespace std;

using ll = long long;

namespace linearSieve {

    const ll N = 100003;
    ll prime[N] = {0},num_prime = 0;
    ll isNotPrime[N] = {1, 1};

    //linearSieve
    void pre() {
        for (ll i = 2 ; i < N; i++) {
            if (!isNotPrime[i])
                prime[num_prime++]=i;
            for(int j = 0; j < num_prime && i * prime[j] <  N ; j++) {
                isNotPrime[i * prime[j]] = 1;
                if (!(i % prime[j]))
                    break;
            }
        }
    }
}

namespace millerRabinAlgo {

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
        if (n < linearSieve::N && !linearSieve::isNotPrime[n]) {
            return true;
        }

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
}

int main() {

    linearSieve::pre();
    ll n, n_copy;
    while (true) {
        scanf("%lld", &n);
        if (n == 0) {
            break;
        }
        bool isPrime = millerRabinAlgo::millerRabinPrimeCheck(n);
        n_copy = n;
        n *= 2;
        while (!millerRabinAlgo::millerRabinPrimeCheck(n)) {
            ++n;
        }
        printf("%lld", n);
        if (!isPrime) {
            printf(" (%lld is not prime)\n", n_copy);
        } else {
            printf("\n");
        }
    }

    return 0;
}
