// https://open.kattis.com/problems/primereduction
//

#include <bits/extc++.h>

using namespace std;
using ll = long long;
constexpr int N = 100003;
constexpr int MAX_FACTORS = 1000;

namespace FastIO {

    template<typename T>
    inline static
    void readInt(T &x) {

        x = 0;
        bool isNeg = false;
        char ch = static_cast<char>(getchar());

        // skip all non digit characters
        while (!isdigit(ch)) {
            if (ch == '-') {
                isNeg = true;
            }
            ch = static_cast<char>(getchar());
        }

        while (isdigit(ch)) {
            x = x * 10 + static_cast<T>(ch ^ 48);
            ch = static_cast<char>(getchar());
        }
        x = isNeg ? -x : x;
    }

    template<typename T>
    inline static
    void writeInt(T x) {
        if (x < 0) {
            x = -x;
            putchar('-');
        }
        static int storeDigits[40];
        int top = 0;
        do {
            storeDigits[top++] = x % 10;
            x /= 10;
        } while (x);
        while (top) {
            putchar(storeDigits[--top] + 48);
        }
    }
}

namespace Factorization {

    ll prime[N] = {0}, num_prime = 0;
    ll isNotPrime[N] = {1, 1};

    void sieve() {
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
        for (ll i = 1; i <= t; i++) {
            result = mult_mod(result, result, n);
            if (result == 1 && last != 1 && last != n - 1)
                return true;
            last = result;
        }
        return (result != 1);
    }

    bool millerRabinPrimeCheck(ll n) {
        const int s = 8; //
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

    ll factor[MAX_FACTORS];    // Save the result of factorizations
    int tol;    //Count of every prime

    ll gcd(ll a, ll b) { //A gcd func which considers the negative nums
        if (a == 0)
            return 1;
        if (a < 0)
            return gcd(-a, b);
        while (b > 0) {
            ll t;
            t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll Pollard_rho(ll x, ll c) {
        ll i = 1, k = 2;
        ll x0 = rand() % x;
        ll y = x0;
        while (true) {
            i++;
            x0 = (mult_mod(x0, x0, x) + c) % x;
            ll d = gcd(y - x0, x);
            if (d != 1 && d != x)
                return d;
            if (y == x0)
                return x;
            if (i == k) {
                y = x0;
                k += k;
            }
        }
    }

    void findfac(ll n) {
        if ((n < 99000 && !isNotPrime[n]) || millerRabinPrimeCheck(n)) {
            factor[tol++] = n;
            return;
        }
        ll p = n;
        while (p >= n)
            p = Pollard_rho(p, rand() % (n - 1) + 1);
        findfac(p);
        findfac(n / p);
    }

    ll getSumOfPrimeFactors(ll n) {
        memset(factor, 0, sizeof(int) * MAX_FACTORS);
        if (n == 2 || n == 3) {
            return n;
        }
        tol = 0;
        findfac(n);
        ll result = 0;
        for (int item = 0; item < tol; item++) {
            result += static_cast<ll>(factor[item]);
        }
        return result;
    }
}

// Save previous answers just in case
unordered_map<ll, pair<ll, ll> > previousAnswer;

int main() {

    // pre
    Factorization::sieve();
    ll n;
    ll nCopy;
    ll counter;
    ll sum;
    ll answer;

    // input
    while (true) {

        FastIO::readInt<ll>(n);
        if (n == 4) {
            break;
        }

        // Check if it is in the previous answer set
        if (previousAnswer.find(n) != previousAnswer.end()) {
            FastIO::writeInt<ll>(previousAnswer[n].first);
            putchar(' ');
            FastIO::writeInt<ll>(previousAnswer[n].second);
            putchar('\n');
            continue;
        }

        nCopy = n;
        counter = 0;
        while (true) {
            sum = Factorization::getSumOfPrimeFactors(n);
            ++counter;
            if (sum == n) {
                answer = sum;
                break;
            }
            n = sum;
        }

        // Update the previous answer set
        previousAnswer[nCopy] = {answer, counter};
        // Output
        FastIO::writeInt<ll>(answer);
        putchar(' ');
        FastIO::writeInt<ll>(counter);
        putchar('\n');
    }

    return 0;
}