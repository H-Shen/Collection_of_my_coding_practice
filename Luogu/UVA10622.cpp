#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int N = 100003;
constexpr int MAX_FACTORS = 1000;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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
        const int s = 8; // Increase its value if the output is not correct!
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

    // Greatest Common Divisor of integers in an array
    ll gcdOfAnArray(const std::vector<ll> &A) {

        // Case 1:
        if (A.empty()) {
            throw std::out_of_range("");
        }

        // Case 2:
        if (A.size() == 1) {
            return abs(A.front());
        }

        // Case 3:
        return accumulate(A.begin(), A.end(), A.front(), gcd);
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
        if ((n < 99900 && !isNotPrime[n]) || millerRabinPrimeCheck(n)) {
            factor[tol++] = n;
            return;
        }
        ll p = n;
        while (p >= n)
            p = Pollard_rho(p, rand() % (n - 1) + 1);
        findfac(p);
        findfac(n / p);
    }

    // output a vector of the times of each prime factor
    vector<ll> getHashmapOfPrimeFactors(ll n) {
        memset(factor, 0, sizeof(int) * MAX_FACTORS);
        vector<ll> result;
        if (n == 2 || n == 3) {
            result.emplace_back(1);
            return result;
        }
        tol = 0;
        findfac(n);
        unordered_map<ll, ll, custom_hash> tempHashmap;
        for (int item = 0; item < tol; item++) {
            ++tempHashmap[static_cast<ll>(factor[item])];
        }
        for (const auto &i : tempHashmap) {
            result.emplace_back(i.second);
        }
        return result;
    }
}

// Save previous answers just in case
unordered_map<ll, ll, custom_hash> previousAnswer;

int main() {

    // pre
    Factorization::sieve();

    ll x;
    ll xCopy;
    ll p;
    bool isNeg;

    // input
    while (true) {

        FastIO::readInt<ll>(x);
        if (x == 0) {
            break;
        }
        xCopy = x;

        // Check if it is in the previous answer set
        if (previousAnswer.find(x) != previousAnswer.end()) {
            FastIO::writeInt<ll>(previousAnswer[x]);
            putchar('\n');
            continue;
        }

        // Process
        isNeg = false;
        if (x < 0) {
            isNeg = true;
            x = -x;
        }
        p = Factorization::gcdOfAnArray(
                Factorization::getHashmapOfPrimeFactors(x));
        if (isNeg) {
            while (p % 2 == 0) {
                p /= 2;
            }
        }
        // Update the previous answer set
        previousAnswer[xCopy] = p;
        // Output
        FastIO::writeInt<ll>(p);
        putchar('\n');
    }

    return 0;
}