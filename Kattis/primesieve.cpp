// https://open.kattis.com/problems/primesieve
#include <bits/extc++.h>

using namespace std;

typedef long long ll;

int primeCnt = 0;

namespace segmentedSieveAlgo {
    void simpleSieve(int limit, vector<int> &prime) {
        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));

        for (int p = 2; p * p < limit; p++) {
            if (mark[p]) {
                for (int i = p * 2; i < limit; i += p)
                    mark[i] = false;
            }
        }

        for (int p = 2; p < limit; p++) {
            if (mark[p]) {
                prime.push_back(p);
                ++primeCnt;
            }
        }
    }

    void segmentedSieve(int n) {
        int limit = floor(sqrt(n)) + 1;
        vector<int> prime;
        simpleSieve(limit, prime);

        int low = limit;
        int high = 2 * limit;

        while (low < n) {
            if (high >= n)
                high = n;

            bool mark[limit + 1];
            memset(mark, true, sizeof(mark));

            for (int i = 0; i < static_cast<int>(prime.size()); i++) {
                int loLim = floor(low / prime[i]) * prime[i];
                if (loLim < low)
                    loLim += prime[i];
                for (int j = loLim; j < high; j += prime[i])
                    mark[j - low] = false;
            }

            for (int i = low; i < high; i++)
                if (mark[i - low])
                    ++primeCnt;

            low = low + limit;
            high = high + limit;
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
    ios_base::sync_with_stdio(false);
    int maxn, q;
    ll val;
    cin >> maxn >> q;
    segmentedSieveAlgo::segmentedSieve(maxn + 1);
    cout << primeCnt << endl;

    while (q--) {
        cin >> val;
        if (millerRabinAlgo::millerRabinPrimeCheck(val)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
